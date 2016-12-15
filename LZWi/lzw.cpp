#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <sys/stat.h>

template <typename Iterator>
Iterator compress(const std::string &uncompressed, Iterator result) {
  // Build the dictionary.
  int dictSize = 256;
  //once the dictionary grows past 2^16, stop growing it
  int maxSize = 65536;
  std::map<std::string,int> dictionary;
  for (int i = 0; i < 256; i++)
    dictionary[std::string(1, i)] = i;

  std::string w;
  for (std::string::const_iterator it = uncompressed.begin(); it != uncompressed.end(); ++it) {
    char c = *it;
    std::string wc = w + c;
    if (dictionary.count(wc))
      w = wc;
    else {
      *result++ = dictionary[w];
      // Add wc to the dictionary.
      if(dictSize < maxSize){
        dictionary[wc] = dictSize++;
      }
      w = std::string(1, c);
    }
  }

  // Output the code for w.
  if (!w.empty())
    *result++ = dictionary[w];
  return result;
}

// Decompress a list of output ks to a string.
// "begin" and "end" must form a valid range of ints
template <typename Iterator>
std::string decompress(Iterator begin, Iterator end) {
  // Build the dictionary.
  int dictSize = 256;
  //once the dictionary grows past 2^16, stop growing it
  int maxSize = 65536;
  std::map<int,std::string> dictionary;
  for (int i = 0; i < 256; i++)
    dictionary[i] = std::string(1, i);

  std::string w(1, *begin++);
  std::string result = w;
  std::string entry;
  for ( ; begin != end; begin++) {
    int k = *begin;
    if (dictionary.count(k))
      entry = dictionary[k];
    else if (k == dictSize)
      entry = w + w[0];
    else
      throw "Bad compressed k";

    result += entry;

    // Add w+entry[0] to the dictionary.
    if(dictSize < maxSize){
        dictionary[dictSize++] = w + entry[0];
    }
    w = entry;
  }
  return result;
}



std::string int2BinaryString(int c, int cl) {
      std::string p = ""; //a binary code string with code length = cl
      while (c>0) {
		   if (c%2==0)
            p="0"+p;
         else
            p="1"+p;
         c=c>>1;
      }
      int zeros = cl-p.size();
      if (zeros<0) {
         std::cout << "\nWarning: Overflow. code is too big to be coded by " << cl <<" bits!\n";
         p = p.substr(p.size()-cl);
      }
      else {
         for (int i=0; i<zeros; i++)  //pad 0s to left of the binary code if needed
            p = "0" + p;
      }
      return p;
}

int binaryString2Int(std::string p) {
   int code = 0;
   if (p.size()>0) {
      if (p.at(0)=='1')
         code = 1;
      p = p.substr(1);
      while (p.size()>0) {
         code = code << 1;
		   if (p.at(0)=='1')
            code++;
         p = p.substr(1);
      }
   }
   return code;
}



//returns a vector with all the integer values from the string of binary numbers
std::vector<int> grabIntsFromCompressedString(std::string binString) {
    std::vector<int> result;
    std::string temp;
    int dictSize = 256;
    int currentBits = 9;
    for(unsigned int i = 0; i < binString.length(); i++) {
        temp += binString[i];
        if(temp.length() >= currentBits) {
            result.push_back(binaryString2Int(temp));
            //we found a word, increment dictSize
            dictSize++;
            //if dictSize fills the current dictionary, increase the bits
            switch(dictSize) {
              case 512:
                currentBits = 10;
                break;
              case 1024:
                currentBits = 11;
                break;
              case 2048:
                currentBits = 12;
                break;
              case 4096:
                currentBits = 13;
                break;
              case 8192:
                currentBits = 14;
                break;
              case 16384:
                currentBits = 15;
                break;
              case 32768:
                currentBits = 16;
                break;
            }
            temp = "";
        }
    }
    if(temp.length() != 0) {
        ///only unused 0's remain
        ///do nothing
    }
    return result;
}


//writes the vector of integers to the file specified
void writeCompressedToFile(std::vector<int> compressed, const char* file) {
   std::string bcode= "";
   std::string p= "";
   int currentBits = 9;
   int dictSize = 256;
   for (std::vector<int>::iterator it = compressed.begin() ; it != compressed.end(); ++it) {
      //write the current integer into the binary string
      p = int2BinaryString(*it, currentBits);
      dictSize++;
      //if our dict size grows beyond the current max, add a bit
      switch(dictSize) {
        case 512:
          currentBits = 10;
          break;
        case 1024:
          currentBits = 11;
          break;
        case 2048:
          currentBits = 12;
          break;
        case 4096:
          currentBits = 13;
          break;
        case 8192:
          currentBits = 14;
          break;
        case 16384:
          currentBits = 15;
          break;
        case 32768:
          currentBits = 16;
          break;
      }
      //std::cout << "c=" << *it <<" : binary string="<<p<<"; back to code=" << binaryString2Int(p)<<"\n";
      bcode+=p;
   }

   //writing to file
   std::ofstream myfile;
   myfile.open(file,  std::ios::binary);

   std::string zeros = "00000000";
   if (bcode.size()%8!=0) //make sure the length of the binary string is a multiple of 8
      bcode += zeros.substr(0, 8-bcode.size()%8);

   int b;
   for (unsigned int i = 0; i < bcode.size(); i+=8) {
      b = 1;
      for (int j = 0; j < 8; j++) {
         b = b<<1;
         if (bcode.at(i+j) == '1')
           b+=1;
      }
      char c = (char) (b & 255); //save the string byte by byte
      myfile.write(&c, 1);
   }
   myfile.close();
}



//reads the compressed specified file into a string of binary numbers
std::string readCompressedFromFile(const std::string filename) {
    std::ifstream myfile2;
    myfile2.open (filename.c_str(),  std::ios::binary);
    struct stat filestatus;
    stat(filename.c_str(), &filestatus );
    long fsize = filestatus.st_size; //get the size of the file in bytes

    std::string zeros = "00000000";

    char c2[fsize];
    myfile2.read(c2, fsize);

    std::string s = "";
    long count = 0;
    while(count<fsize) {
      unsigned char uc =  (unsigned char) c2[count];
      std::string p = ""; //a binary string
      for (int j=0; j<8 && uc>0; j++) {
           if (uc%2==0)
            p="0"+p;
         else
            p="1"+p;
         uc=uc>>1;
      }
      p = zeros.substr(0, 8-p.size()) + p; //pad 0s to left if needed
      s+= p;
      count++;
    }
    myfile2.close();
    return s;
}

//reads all bytes of a file, returns into a string
std::string readAllBytes(char const* filename) {
    std::ifstream f(filename);
    std::string theString((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    f.close();
    return theString;
}

//writes all bytes from the string into the desired file
void writeAllBytes(std::string &message, std::string filename) {
    std::ofstream fout(filename.c_str());
    fout << message;
    fout.close();
}
