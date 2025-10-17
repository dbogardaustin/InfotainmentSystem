#include "brightnesscontrol.h"
#include "ui_brightnesscontrol.h"
#include "mainwindow.h"
#include <softPwm.h>

static int brightnessValue = 0;
static MainWindow *mainWindow;

BrightnessControl::BrightnessControl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrightnessControl)
{
    ui->setupUi(this);
    ui->progressBar->setValue(brightnessValue);
    ui->horizontalSlider->setValue(brightnessValue);
}

BrightnessControl::~BrightnessControl()
{
    delete ui;
}

void BrightnessControl::on_pushButton_clicked()
{
    hide();
    mainWindow = new MainWindow(this);
    mainWindow->show();
}

void BrightnessControl::on_horizontalSlider_valueChanged(int value)
{
    brightnessValue = value;
    ui->progressBar->setValue(brightnessValue);
    softPwmCreate(22, 0, 100);
    softPwmWrite(22,brightnessValue);
}

void BrightnessControl::on_brightButton_clicked()
{
    softPwmCreate(22, 0, 100);
    softPwmWrite(22,100);
    brightnessValue = 100;
    ui->progressBar->setValue(brightnessValue);
    ui->horizontalSlider->setValue(brightnessValue);
}

void BrightnessControl::on_dimButton_clicked()
{
    softPwmCreate(22, 0, 100);
    softPwmWrite(22,10);
    brightnessValue = 10;
    ui->progressBar->setValue(brightnessValue);
    ui->horizontalSlider->setValue(brightnessValue);
}
