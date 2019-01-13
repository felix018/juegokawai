#include "menu1.h"
#include "ui_menu1.h"
#include <QMessageBox>
#include <QString>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include "stdlib.h"
#include "game.h"

extern game *gamm;
extern int a;

using namespace std;
menu1::menu1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu1)
{
    ui->setupUi(this);
    ui->saved->setStyleSheet("QPushButton { background-color : transparent; color : white; }");
    ui->return_2->setStyleSheet("QPushButton { background-color : transparent; color : white; }");
    playing =new QMediaPlayer(this);
    playing->setMedia(QUrl(":/OmegaVH19_Trim (online-audio-converter.com).mp3"));
    playing->play();

}

menu1::~menu1()
{
    delete ui;
}

void menu1::on_lineEdit_editingFinished()
{

}
void menu1::on_return_2_clicked(){
    MainWindow*menu1= new MainWindow;
    menu1->show();
    close();

}
void menu1::on_saved_clicked(){
    QString respuesta1=ui->respuesta->text();
    respuesta1=respuesta1.toLower();
    if(respuesta1=="japón"){

        QString h = ui->usuario->text()+".txt";
        b = h.toLocal8Bit().constData();
        ofstream tenga;

        qDebug()<<"guardado"<<endl;
        qDebug()<<h<<endl;

        tenga.open(b,ios::out);
        if(tenga.fail())cout<<"NELL"<<endl;
        gamm = new game();
        gamm->iniciar(a);

        gamm->show();
        close();

    }else{
        QMessageBox::information(this,tr("error"),tr("mal amigo").arg(respuesta1));
    }
}
