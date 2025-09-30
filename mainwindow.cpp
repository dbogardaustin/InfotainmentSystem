#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_headlights_clicked()
{

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
