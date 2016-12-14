/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *Imagen;
    QLabel *labelOriginal;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QFrame *line;
    QLabel *label_3;
    QLineEdit *lineEdit_1;
    QPushButton *btn_open_img;
    QLabel *label_9;
    QLabel *label_propiedades;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *Imagen_2;
    QLabel *labelDescompresa;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *lineEdit_2;
    QPushButton *btn_open_imgdesc;
    QLabel *label_10;
    QLabel *label;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btn_comprimir;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label_7;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QLabel *label_8;
    QMenuBar *menuBar;
    QMenu *menuALgoritmo_de_LZW;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1045, 742);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 40, 381, 381));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Imagen = new QLabel(verticalLayoutWidget);
        Imagen->setObjectName(QStringLiteral("Imagen"));

        verticalLayout->addWidget(Imagen);

        labelOriginal = new QLabel(verticalLayoutWidget);
        labelOriginal->setObjectName(QStringLiteral("labelOriginal"));
        labelOriginal->setFrameShape(QFrame::Box);

        verticalLayout->addWidget(labelOriginal);

        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(20, 430, 471, 80));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        line = new QFrame(verticalLayoutWidget_2);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        lineEdit_1 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_1->setObjectName(QStringLiteral("lineEdit_1"));

        horizontalLayout->addWidget(lineEdit_1);

        btn_open_img = new QPushButton(verticalLayoutWidget_2);
        btn_open_img->setObjectName(QStringLiteral("btn_open_img"));

        horizontalLayout->addWidget(btn_open_img);


        verticalLayout_3->addLayout(horizontalLayout);

        label_9 = new QLabel(verticalLayoutWidget_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_3->addWidget(label_9);

        label_propiedades = new QLabel(verticalLayoutWidget_2);
        label_propiedades->setObjectName(QStringLiteral("label_propiedades"));

        verticalLayout_3->addWidget(label_propiedades);

        verticalLayoutWidget_3 = new QWidget(centralWidget);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(610, 40, 391, 381));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        Imagen_2 = new QLabel(verticalLayoutWidget_3);
        Imagen_2->setObjectName(QStringLiteral("Imagen_2"));

        verticalLayout_4->addWidget(Imagen_2);

        labelDescompresa = new QLabel(verticalLayoutWidget_3);
        labelDescompresa->setObjectName(QStringLiteral("labelDescompresa"));
        labelDescompresa->setFrameShape(QFrame::Box);

        verticalLayout_4->addWidget(labelDescompresa);

        verticalLayoutWidget_4 = new QWidget(centralWidget);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(570, 430, 471, 81));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(verticalLayoutWidget_4);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget_4);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);

        btn_open_imgdesc = new QPushButton(verticalLayoutWidget_4);
        btn_open_imgdesc->setObjectName(QStringLiteral("btn_open_imgdesc"));

        horizontalLayout_2->addWidget(btn_open_imgdesc);


        verticalLayout_5->addLayout(horizontalLayout_2);

        label_10 = new QLabel(verticalLayoutWidget_4);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_5->addWidget(label_10);

        label = new QLabel(verticalLayoutWidget_4);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_5->addWidget(label);

        horizontalLayoutWidget_3 = new QWidget(centralWidget);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(0, 520, 1021, 86));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        btn_comprimir = new QPushButton(horizontalLayoutWidget_3);
        btn_comprimir->setObjectName(QStringLiteral("btn_comprimir"));

        horizontalLayout_4->addWidget(btn_comprimir);

        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_6 = new QLabel(horizontalLayoutWidget_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_6->addWidget(label_6);

        label_2 = new QLabel(horizontalLayoutWidget_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_6->addWidget(label_2);

        label_7 = new QLabel(horizontalLayoutWidget_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_6->addWidget(label_7);

        pushButton_2 = new QPushButton(horizontalLayoutWidget_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_6->addWidget(pushButton_2);


        horizontalLayout_4->addLayout(verticalLayout_6);

        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(horizontalLayoutWidget_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_4->addWidget(pushButton);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(380, 0, 281, 31));
        QFont font;
        font.setPointSize(18);
        label_8->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        verticalLayoutWidget->raise();
        verticalLayoutWidget_2->raise();
        verticalLayoutWidget_3->raise();
        verticalLayoutWidget_4->raise();
        horizontalLayoutWidget_3->raise();
        label_8->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1045, 19));
        menuALgoritmo_de_LZW = new QMenu(menuBar);
        menuALgoritmo_de_LZW->setObjectName(QStringLiteral("menuALgoritmo_de_LZW"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuALgoritmo_de_LZW->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        Imagen->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Imagen Original</p></body></html>", 0));
        labelOriginal->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_3->setText(QApplication::translate("MainWindow", "DIrectorio:", 0));
        btn_open_img->setText(QApplication::translate("MainWindow", "Abrir", 0));
        label_9->setText(QApplication::translate("MainWindow", "Informacion:", 0));
        label_propiedades->setText(QString());
        Imagen_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Imagen Descompresa</p></body></html>", 0));
        labelDescompresa->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_5->setText(QApplication::translate("MainWindow", "DIrectorio:", 0));
        btn_open_imgdesc->setText(QApplication::translate("MainWindow", "Abrir", 0));
        label_10->setText(QApplication::translate("MainWindow", "Informacion:", 0));
        label->setText(QString());
        btn_comprimir->setText(QApplication::translate("MainWindow", "Comprimir", 0));
        label_6->setText(QApplication::translate("MainWindow", "Informacion Archivo Compreso", 0));
        label_2->setText(QApplication::translate("MainWindow", "Directorio:  ", 0));
        label_7->setText(QApplication::translate("MainWindow", "Tama\303\261o: ", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Abrir ", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Descomprimir", 0));
        label_8->setText(QApplication::translate("MainWindow", "ALGORITMO DE LZW", 0));
        menuALgoritmo_de_LZW->setTitle(QApplication::translate("MainWindow", "ALgoritmo de LZW", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
