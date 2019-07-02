#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <iomanip>
//const float B = ; //Atribuir o valor constante da distancia do eixo entre rodaD e rodaE
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //rodaD = 0, rodaE = 0;
    attack = "A";
    attack2 = "B";
    attackLigado = 0;
    attackLigado2 = 0;
    energia = 0;
//    Parar;
    this->WIFIClient = NULL;

}

MainWindow::~MainWindow()
{
    delete ui;
    if(this->WIFIClient)
        {
          delete this->WIFIClient;
          this->WIFIClient = NULL;
        }
}

void MainWindow::on_conectar_clicked()
{
    this->WIFIClient = new Client(ui->IP->text(), ui->PORTA->text().toInt());
    connect(this->WIFIClient, SIGNAL(connectionSuccessful()),this, SLOT(conectado));
    ac = new AccelHandler(QAccelerometer::Combined, 200);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(enviarMensagem()));
    timer->start(200);
}

void MainWindow::conectado()
{
   QMessageBox msgBox;
   msgBox.setText("CONECTADO!");
   msgBox.exec();
}

void MainWindow::on_PARAR_clicked()
{
    if(energia == 1)
    {
        attack = " ;";
        attack2 = " ;";
        attackLigado = 0;
        attackLigado2 = 0;
        V = 0;
        W = 0;
    }
    else if(energia == 0)
    {
        energia = 1;
        ui->PARAR->setText("PARADO!");
    }
}

void MainWindow::on_Attack1_clicked()
{
    std::stringstream attack;
    attack << this->attack << '\r';
    this->WIFIClient->writeData(attack.str().c_str());
}

void MainWindow::on_Attack2_clicked()
{
    std::stringstream attack2;
    attack2 << this->attack2 << '\r';
    this->WIFIClient->writeData(attack2.str().c_str());
}

void MainWindow::on_Velocidade_sliderMoved(int position)
{
    ui->label_4->setText(QString::number(position));
    this->V = position;
    std::stringstream ss1,ss3;
    ss1 << '1';
    if(V > 0){
        ss3 << V;
        if(ss3.str().length() == 5)
            ss1 << V << '\r';
        if(ss3.str().length() == 4)
            ss1 << '0' << V <<  '\r';
        if(ss3.str().length() == 3)
            ss1 << "00" << V <<  '\r';
        if(ss3.str().length() == 2)
            ss1 << "000"  << V << '\r';
        if(ss3.str().length() == 1)
            ss1 << "0000"  << V << '\r';
    }
    else {
        V = -V;
        ss3 << V;
        if(ss3.str().length() == 4)
            ss1 << '-' << V <<  '\r';
        if(ss3.str().length() == 3)
            ss1 << "-0" << V << '\r';
        if(ss3.str().length() == 2)
            ss1 << "-00" << V << '\r';
        if(ss3.str().length() == 1)
            ss1 << "-000" << V << '\r';
    }
//    this->WIFIClient->writeData(ss1.str().c_str());
    ui->lineEdit->setText(ss1.str().c_str());
}

void MainWindow::on_Velocidade_2_sliderMoved(int position)
{
    ui->label_5->setText(QString::number(position));
    this->W = position;
    std::stringstream ss1,ss3;
    ss1 << '1';
    if(W > 0){
        ss3 << W;
        if(ss3.str().length() == 5)
            ss1 << W << '\r';
        if(ss3.str().length() == 4)
            ss1 << '0' << W <<  '\r';
        if(ss3.str().length() == 3)
            ss1 << "00" << W <<  '\r';
        if(ss3.str().length() == 2)
            ss1 << "000"  << W << '\r';
        if(ss3.str().length() == 1)
            ss1 << "0000"  << W << '\r';
    }
    else {
        W = -W;
        ss3 << W;
        if(ss3.str().length() == 4)
            ss1 << '-' << W <<  '\r';
        if(ss3.str().length() == 3)
            ss1 << "-0" << W << '\r';
        if(ss3.str().length() == 2)
            ss1 << "-00" << W << '\r';
        if(ss3.str().length() == 1)
            ss1 << "-000" << W << '\r';
    }
//    this->WIFIClient->writeData(ss1.str().c_str());
    ui->lineEdit_2->setText(ss1.str().c_str());
}

void MainWindow::enviarMensagem()
{

}

void MainWindow::on_IP_cursorPositionChanged(int arg1, int arg2)
{
    ui->IP->setText("192.168.0.100");
}

void MainWindow::on_PORTA_cursorPositionChanged(int arg1, int arg2)
{
    ui->PORTA->setText("5000");
}
