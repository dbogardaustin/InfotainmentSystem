#include "interiorlights.h"
#include "ui_interiorlights.h"
#include "mainwindow.h"

static bool front = false;
static bool mid = false;
static bool back = false;

static MainWindow *mainWindow;

InteriorLights::InteriorLights(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InteriorLights)
{
    ui->setupUi(this);
    ui->Front->setChecked(front);
    ui->Mid->setChecked(mid);
    ui->Back->setChecked(back);
    wiringPiSetupGpio();
    pinMode(22,OUTPUT);
    pinMode(21,OUTPUT);
    pinMode(20,OUTPUT);
    pinMode(19,OUTPUT);
    pinMode(18,OUTPUT);
    pinMode(17,OUTPUT);
}

InteriorLights::~InteriorLights()
{
    delete ui;
}

void InteriorLights::on_pushButton_clicked()
{
    hide();
    mainWindow = new MainWindow(this);
    mainWindow->show();
}

void InteriorLights::on_Front_stateChanged(int arg1)
{
    if(arg1==0){
        front = false;
        digitalWrite(22,LOW);
        digitalWrite(21,LOW);
    }
    else{
        front = true;
        digitalWrite(22,HIGH);
        digitalWrite(21,HIGH);
    }
}

void InteriorLights::on_Mid_stateChanged(int arg1)
{
    if(arg1==0){
        mid = false;
        digitalWrite(20,LOW);
        digitalWrite(19,LOW);
    }
    else{
        mid = true;
        digitalWrite(20,HIGH);
        digitalWrite(19,HIGH);
    }

}

void InteriorLights::on_Back_stateChanged(int arg1)
{
    if(arg1==0){
        back = false;
        digitalWrite(18,LOW);
        digitalWrite(17,LOW);
    }
    else{
        back = true;
        digitalWrite(18,HIGH);
        digitalWrite(17,HIGH);
    }

}

void InteriorLights::on_resetButton_clicked()
{
    digitalWrite(22,LOW);
    digitalWrite(21,LOW);
    digitalWrite(20,LOW);
    digitalWrite(19,LOW);
    digitalWrite(18,LOW);
    digitalWrite(17,LOW);
    front = false;
    mid = false;
    back = false;

    ui->Front->setChecked(front);
    ui->Mid->setChecked(mid);
    ui->Back->setChecked(back);

}
