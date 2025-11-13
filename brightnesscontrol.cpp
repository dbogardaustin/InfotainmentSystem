#include "brightnesscontrol.h"
#include "ui_brightnesscontrol.h"
#include <wiringPi.h>
#include <gpioconstants.h>
#include <softPwm.h>

static int brightnessValue = 0;

BrightnessControl::BrightnessControl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrightnessControl)
{
    ui->setupUi(this);
    ui->progressBar->setValue(brightnessValue);
    ui->horizontalSlider->setValue(brightnessValue);
    this->parent = parent;
}

BrightnessControl::~BrightnessControl()
{
    delete ui;
}

void BrightnessControl::on_pushButton_clicked()
{
    hide();
    parent->show();
}

void BrightnessControl::on_horizontalSlider_valueChanged(int value)
{
    brightnessValue = value;
    ui->progressBar->setValue(brightnessValue);
    softPwmCreate(FRONT_LEFT_INTERIOR_GPIO, 0, 100);
    softPwmWrite(FRONT_LEFT_INTERIOR_GPIO,brightnessValue);
}

void BrightnessControl::on_brightButton_clicked()
{
    softPwmCreate(FRONT_LEFT_INTERIOR_GPIO, 0, 100);
    softPwmWrite(FRONT_LEFT_INTERIOR_GPIO,100);
    brightnessValue = 100;
    ui->progressBar->setValue(brightnessValue);
    ui->horizontalSlider->setValue(brightnessValue);
}

void BrightnessControl::on_dimButton_clicked()
{
    softPwmCreate(FRONT_LEFT_INTERIOR_GPIO, 0, 100);
    softPwmWrite(FRONT_LEFT_INTERIOR_GPIO,10);
    brightnessValue = 10;
    ui->progressBar->setValue(brightnessValue);
    ui->horizontalSlider->setValue(brightnessValue);
}
