#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gpioconstants.h"
#include <wiringPi.h>
#include <softPwm.h>


static int hornPWM = 0;
static bool headlightsOn = false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    hornTimer = new QTimer(this);
    hornTimer->setInterval(1);
    connect(hornTimer, &QTimer::timeout, this, &MainWindow::carHorn);

    wiringPiSetupGpio();
    pinMode(FRONT_RIGHT_INTERIOR_GPIO, OUTPUT);
    pinMode(FRONT_LEFT_INTERIOR_GPIO, OUTPUT);
    pinMode(CENTER_RIGHT_INTERIOR_GPIO, OUTPUT);
    pinMode(CENTER_LEFT_INTERIOR_GPIO, OUTPUT);
    pinMode(BACK_RIGHT_INTERIOR_GPIO, OUTPUT);
    pinMode(BACK_LEFT_INTERIOR_GPIO, OUTPUT);
    pinMode(HEADLIGHTS_GPIO, OUTPUT);

    if (headlightsOn) {
        ui->headlights->setStyleSheet("background-color:rgb(255,255,192)");// on when true
        digitalWrite(HEADLIGHTS_GPIO, HIGH);
    } else {
        ui->headlights->setStyleSheet("background-color:rgb(135,135,135)");// off when false
        digitalWrite(HEADLIGHTS_GPIO, LOW);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_headlights_clicked()
{
    if(headlightsOn){
        headlightsOn = false;
        ui->headlights->setStyleSheet("background-color:rgb(135,135,135)");// headlights now off
        digitalWrite(HEADLIGHTS_GPIO, LOW);
    }
    else{
        headlightsOn = true;
        ui->headlights->setStyleSheet("background-color:rgb(255,255,192)");// headlights now on
        digitalWrite(HEADLIGHTS_GPIO, HIGH);
    }
}

void MainWindow::on_about_clicked()
{
    hide();
    about = new About(this);
    about->show();
}

void MainWindow::on_brightnessControl_clicked()
{
    hide();
    brightnessControl = new BrightnessControl(this);
    brightnessControl->show();
}

void MainWindow::on_interiorLights_clicked()
{
    hide();
    interiorLights = new InteriorLights(this);
    interiorLights->show();
}


void MainWindow::on_Horn_pressed()
{
    hornTimer->start();
//     softPwmCreate(HORN_GPIO, 0, 100);
}

void MainWindow::carHorn(){
    hornPWM = (hornPWM + 1) % 2;
    qInfo() << "PWM SET TO: " << hornPWM << "\n";
    digitalWrite(HORN_GPIO, hornPWM);
//    softPwmWrite(HORN_GPIO, hornPWM);
//    if(hornPWM==0){
//       softPwmWrite(HORN_GPIO,0);
//    }
//    else{
//        softPwmWrite(HORN_GPIO,hornPWM);
//    }
}




void MainWindow::on_Horn_released()
{
    hornTimer->stop();
    hornPWM = 0;
    digitalWrite(HORN_GPIO, 0);
//    softPwmWrite(HORN_GPIO, hornPWM);
}
