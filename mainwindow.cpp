#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <wiringPi.h>

static bool headlightsOn = false;
//static const int front_red1_gpio = 19;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wiringPiSetupGpio();
    pinMode(22,OUTPUT);
    pinMode(front_red1_gpio,OUTPUT);
    pinMode(26,OUTPUT);
    pinMode(21,OUTPUT);
    pinMode(20,OUTPUT);
    pinMode(16,OUTPUT);
    pinMode(12,OUTPUT);
    if (headlightsOn){
        ui->headlights->setStyleSheet("background-color:rgb(255,255,192)");// on when true
        digitalWrite(12,HIGH);
    }
    else{
        ui->headlights->setStyleSheet("background-color:rgb(135,135,135)");// off when false
        digitalWrite(12,LOW);
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
        digitalWrite(12,LOW);
    }
    else{
        headlightsOn = true;
        ui->headlights->setStyleSheet("background-color:rgb(255,255,192)");// headlights now on
        digitalWrite(12,HIGH);
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

