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
 // moved to mainwindow
 //   wiringPiSetupGpio();
 //   pinMode(22,OUTPUT);
 //   pinMode(19,OUTPUT);
 //   pinMode(26,OUTPUT);
 //   pinMode(21,OUTPUT);
 //   pinMode(20,OUTPUT);
 //   pinMode(16,OUTPUT);
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
    if(arg1 == 0){
        front = false;
        digitalWrite(22,LOW);
        digitalWrite(front_red1_gpio,LOW);
    }
    else{
        front = true;
        digitalWrite(22,HIGH);
        digitalWrite(front_red1_gpio,HIGH);
    }
}

void InteriorLights::on_Mid_stateChanged(int arg1)
{
    if(arg1 == 0){
        mid = false;
        digitalWrite(26,LOW);
        digitalWrite(21,LOW);
    }
    else{
        mid = true;
        digitalWrite(26,HIGH);
        digitalWrite(21,HIGH);
    }

}

void InteriorLights::on_Back_stateChanged(int arg1)
{
    if(arg1 == 0){
        back = false;
        digitalWrite(20,LOW);
        digitalWrite(16,LOW);
    }
    else{
        back = true;
        digitalWrite(20,HIGH);
        digitalWrite(16,HIGH);
    }

}

void InteriorLights::on_resetButton_clicked()
{
    front = false;
    ui->Front->setChecked(front);
    digitalWrite(22,LOW);
    digitalWrite(front_red1_gpio,LOW);

    mid = false;
    ui->Mid->setChecked(mid);
    digitalWrite(26,LOW);
    digitalWrite(21,LOW);

    back = false;
    ui->Back->setChecked(back);
    digitalWrite(20,LOW);
    digitalWrite(16,LOW);
}
