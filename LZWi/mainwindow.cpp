#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lzw.cpp"
#include <QImage>
#include <iostream>
#include <QFile>
#include <qfiledialog.h>
#include <QTextStream>
using namespace std;

//string cORe = "d";
string filename_img;
string compressed_filename_img;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * Funcion para cargar el archivo original ppm
 */
int tam=0; // tamaño original
void MainWindow::on_btn_open_img_clicked()
{

    QString fileName1 = QFileDialog::getOpenFileName(
                            this,
                            "Select one or more files to open",
                            "/home",
                            "Images (*.ppm *.pgm *.bmp)");
    QFile file1(fileName1);
     if(!file1.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

     QTextStream in(&file1);
     while(!in.atEnd())
     {
        QString line = in.readLine();
     }


    ui->lineEdit_1->setText(QFileInfo(file1).filePath());


    /* aqui carga la dirreccion y manda levantar*/

    QString filename = ui->lineEdit_1->text();
    filename_img = filename.toStdString();
    cout<<"IMG:    |"<<filename_img<<"|"<<endl;
    QImage image( filename );
    if( image.isNull() )
    {
        cout<<"error , no se pudo cargar la imagen"<<endl;
    }
     ui->labelOriginal->setPixmap(QPixmap::fromImage( image ));


     // Para mostrar el tamaño de la imagen en bits
    tam=file1.size();
    ui->label_propiedades->setText("Tamaño original : \n"+QString::number(tam) + " bits ");

}

/*
 * Funcion para comprimir la imagen cargada /home/micaela/build-LZWi-Desktop_Qt_5_7_0_GCC_64bit-Debug
 */

void MainWindow::on_btn_comprimir_clicked(){
            std::vector<int> compressed;
            //saves filenames into local variables
            const char* cstrFilename = filename_img.c_str();
            std::string newFilename = filename_img + ".lzw";
            compressed_filename_img = newFilename;

            const char* cstrNewFilename = newFilename.c_str();
            //stores file contents into message variable
            std::string message = readAllBytes(cstrFilename);
            compress(message, back_inserter(compressed));
            writeCompressedToFile(compressed, cstrNewFilename);
            cout<<"comprimido"<<endl;
            cout<<"img comprimida: "<<compressed_filename_img<<endl;

            ui->plainTextEdit->setPlainText("Directorio: " +  QString::fromLocal8Bit(compressed_filename_img.c_str()));
            //ui->label_2->setText("Directorio: " +  QString::fromLocal8Bit(compressed_filename_img.c_str()));
            QFile file(QString::fromLocal8Bit(compressed_filename_img.c_str()));

            int tama= file.size();
            ui->label_7->setText("Tamaño :" + QString::number(tama) + " bits " );


            /*Porcentaje de compression*/

            ui->label_4->setText("Porcentaje de compresión: "+QString::number(100 -(tama*100.0/tam))+ " %");

}

/*
 * Funcio para abrir el archivo compreso
 */

void MainWindow::on_pushButton_2_clicked(){




    QString fileName1 = QFileDialog::getOpenFileName(
                            this,
                            "Select one or more files to open",
                            "/home",
                            "Images ( *.lzw)");
    QFile file1(fileName1);
     if(!file1.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

     QTextStream in(&file1);
     while(!in.atEnd())
     {
        QString line = in.readLine();
     }


    compressed_filename_img=fileName1.toStdString();

    QFile file(QString::fromLocal8Bit(compressed_filename_img.c_str()));
    int tam_img= file.size();
    ui->plainTextEdit->setPlainText(compressed_filename_img.c_str());
    ui->label_7->setText( QString::number(tam_img) );



}


/*
 * funcin para descomprimir la imagen seleccionada
 */
void MainWindow::on_pushButton_clicked(){
    std::vector<int> compressed;
    //grab compressed binary data from file and store it in a string
    std::string binaryFileString = readCompressedFromFile(compressed_filename_img);

    //place the compressed data into a vector for decompression
    compressed = grabIntsFromCompressedString(binaryFileString);

    //execute decompression
    std::string decompressed = decompress(compressed.begin(), compressed.end());

    //adjust the filename so that it is a newly name version of original non-compressed file
    std::string newFilename = compressed_filename_img.substr(0,compressed_filename_img.size()-8);
    newFilename = newFilename + "2.ppm";

    writeAllBytes(decompressed, newFilename);
    cout<<"img comprimida:" <<compressed_filename_img<<endl;
    cout<<"descomprimido img: "<<newFilename<<endl;

    ui->lineEdit_2->setText(QString::fromLocal8Bit(newFilename.c_str()));


     QFile file2(QString::fromLocal8Bit(newFilename.c_str()));

    ui->label_10->setText("Informacion: \n "+QString::number(file2.size()));


    QString QnewFilename = QString::fromLocal8Bit(newFilename.c_str());
    QImage image( QnewFilename );
    ui->labelDescompresa->setPixmap(QPixmap::fromImage( image ));
    //ui->labelOriginal->setPixmap(QPixmap::fromImage( image ));
}


/*
 * funcion para abrir el archivo compreso listo para descomprimir
 */

void MainWindow::on_btn_open_imgdesc_clicked(){

}
