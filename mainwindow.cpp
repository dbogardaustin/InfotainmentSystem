#include "mainwindow.h"
#include "ui_mainwindow.h"
static bool headlightsOn = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(headlightsOn){
        ui->headlights->setStyleSheet("background-color:rgb(250,250,192)");
    }
    else{
        ui->headlights->setStyleSheet("background-color:rgb(135,135,135)");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
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

void MainWindow::on_headlights_clicked()
{
    if(headlightsOn==true){
        headlightsOn = false;
        ui->headlights->setStyleSheet("background-color:rgb(135,135,135)");
    }
    else{
        headlightsOn = true;
        ui->headlights->setStyleSheet("background-color:rgb(250,250,192)");
    }
}
