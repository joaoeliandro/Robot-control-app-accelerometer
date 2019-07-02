#ifndef MAINWINDOW_H
#define MAINW8INDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <accelhandler.h>
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
#include <string>
#include "client.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void enviarMensagem();

    void conectado();

    void on_conectar_clicked();

    void on_PARAR_clicked();

    void on_Attack1_clicked();

    void on_Attack2_clicked();

    //void on_Velocidade_actionTriggered(int action);

    void on_IP_cursorPositionChanged(int arg1, int arg2);

    void on_PORTA_cursorPositionChanged(int arg1, int arg2);

    //void on_Velocidade_sliderReleased();

    void on_Velocidade_sliderMoved(int position);

    void on_Velocidade_2_sliderMoved(int position);



private: //declarar todas as variaveis globais no private
    Ui::MainWindow *ui;
    Client *WIFIClient;
    AccelHandler *ac;
    QTimer *timer;
    //double rodaD = 3.5;
    //double rodaE = 3.4;
    //const float B = ;
    int V, W;
    string attack = "A";
    string attack2 = "B";
    int attackLigado;
    int attackLigado2;
    int energia;
//    int Parar;

};

#endif // MAINWINDOW_H
