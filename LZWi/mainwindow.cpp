#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <iostream>
#include <QFile>
#include <qfiledialog.h>
#include <QTextStream>

using namespace std;

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

void MainWindow::on_btn_open_img_clicked()
{

    //QString fileName1 = QFileDialog::getOpenFileName(this,tr("Open Text File"), "", tr("Text Files (*.ppm)"),);

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
    int tam=0;

    ui->lineEdit_1->setText(QFileInfo(file1).filePath());


    /* aqui carga la dirreccion y manda levantar*/

    QString filename = ui->lineEdit_1->text();
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

void MainWindow::on_btn_comprimir_clicked()
{

}

/*
 * Funcio para abrir el archivo compreso
 */

void MainWindow::on_pushButton_2_clicked()
{

}

/*
 * funcin para descomprimir la imagen seleccionada
 */

void MainWindow::on_pushButton_clicked()
{

}


/*
 * funcion para abrir el archivo compreso listo para descomprimir
 */

void MainWindow::on_btn_open_imgdesc_clicked()
{

}
