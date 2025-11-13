#include "interiorlights.h"
#include "ui_interiorlights.h"
#include "wiringPi.h"
#include <gpioconstants.h>

static bool front = false;
static bool mid = false;
static bool back = false;

InteriorLights::InteriorLights(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InteriorLights)
{
    this->parent = parent;
    ui->setupUi(this);
    ui->Front->setChecked(front);
    ui->Mid->setChecked(mid);
    ui->Back->setChecked(back);
}

InteriorLights::~InteriorLights()
{
    delete ui;
}

void InteriorLights::on_pushButton_clicked()
{
    hide();
    parent->show();
}

void InteriorLights::on_Front_stateChanged(int arg1)
{
    if(arg1 == 0){
        front = false;
        digitalWrite(FRONT_LEFT_INTERIOR_GPIO, LOW);
        digitalWrite(FRONT_RIGHT_INTERIOR_GPIO, LOW);
    }
    else{
        front = true;
        digitalWrite(FRONT_LEFT_INTERIOR_GPIO, HIGH);
        digitalWrite(FRONT_RIGHT_INTERIOR_GPIO, HIGH);
    }
}

void InteriorLights::on_Mid_stateChanged(int arg1)
{
    if(arg1 == 0){
        mid = false;
        digitalWrite(CENTER_LEFT_INTERIOR_GPIO, LOW);
        digitalWrite(CENTER_RIGHT_INTERIOR_GPIO, LOW);
    }
    else{
        mid = true;
        digitalWrite(CENTER_LEFT_INTERIOR_GPIO, HIGH);
        digitalWrite(CENTER_RIGHT_INTERIOR_GPIO, HIGH);
    }

}

void InteriorLights::on_Back_stateChanged(int arg1)
{
    if(arg1 == 0){
        back = false;
        digitalWrite(BACK_LEFT_INTERIOR_GPIO, LOW);
        digitalWrite(BACK_RIGHT_INTERIOR_GPIO, LOW);
    }
    else{
        back = true;
        digitalWrite(BACK_LEFT_INTERIOR_GPIO, HIGH);
        digitalWrite(BACK_RIGHT_INTERIOR_GPIO, HIGH);
    }

}

void InteriorLights::on_resetButton_clicked()
{
    front = false;
    ui->Front->setChecked(front);
    digitalWrite(FRONT_LEFT_INTERIOR_GPIO, LOW);
    digitalWrite(FRONT_RIGHT_INTERIOR_GPIO, LOW);

    mid = false;
    ui->Mid->setChecked(mid);
    digitalWrite(CENTER_LEFT_INTERIOR_GPIO, LOW);
    digitalWrite(CENTER_RIGHT_INTERIOR_GPIO, LOW);

    back = false;
    ui->Back->setChecked(back);
    digitalWrite(BACK_LEFT_INTERIOR_GPIO, LOW);
    digitalWrite(BACK_RIGHT_INTERIOR_GPIO, LOW);
}
