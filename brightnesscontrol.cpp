#include "brightnesscontrol.h"
#include "ui_brightnesscontrol.h"
#include "mainwindow.h"

static MainWindow *mainWindow;

BrightnessControl::BrightnessControl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrightnessControl)
{
    ui->setupUi(this);
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
