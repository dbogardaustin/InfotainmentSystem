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
    pinMode(HORN_GPIO, OUTPUT);

    circuitButton = new CircuitButton(this, HORN_BUTTON_GPIO);
    connect(circuitButton, &CircuitButton::buttonPressed, this, &MainWindow::on_Horn_pressed, Qt::QueuedConnection);
    connect(circuitButton, &CircuitButton::buttonReleased, this, &MainWindow::on_Horn_released, Qt::QueuedConnection);

    if (headlightsOn) {
        ui->headlights->setStyleSheet("background-color:rgb(255,255,192)");// on when true
    } else {
        ui->headlights->setStyleSheet("background-color:rgb(135,135,135)");// off when false
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
    }
    else{
        headlightsOn = true;
        ui->headlights->setStyleSheet("background-color:rgb(255,255,192)");// headlights now on
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
    ui->Horn->setStyleSheet("border-radius:80; border-color:rgb(0,0,0); border-style:solid; border-width:3; background-color:rgb(255,0,0)");
}

void MainWindow::carHorn() {
    hornPWM = (hornPWM + 1) % 2;
    qInfo() << "PWM SET TO: " << hornPWM;
    digitalWrite(HORN_GPIO, hornPWM);
}


void MainWindow::on_Horn_released()
{
    hornTimer->stop();
    hornPWM = 0;
    digitalWrite(HORN_GPIO, 0);
//    softPwmWrite(HORN_GPIO, hornPWM);
    ui->Horn->setStyleSheet("border-radius:80; border-color:rgb(0,0,0); border-style:solid; border-width:3; background-color: rgb(240, 240, 240)");
}

// Global pointer to Qt object (e.g. MainWindow)
// This is necessary to emit a signal
// static MyQtClass* s_myQtObject = nullptr;
//
//void myISRHandler(){
//    if(s_mQtObject){
//        //emit a Qt signal from the ISR
//        // This must be done carefully to issues with threads and Qt's event loop.
//        // Using a queued connection is often best.
//        s_myObject->emitInterruptSignal();
//    }
//}
//void setupWiringPiISR(int pin, MyQtClass* qtObject){
//    wiringPiSetupGpio();
//    pinMode(HORN_INT_GPIO, INPUT);
//    pullUpDnControl(HORN_INT_GPIO, PUD_UP);
//    s_myQtObject = qtObject; // Assign the Qt object pointer
    // Register the ISR
//    wiringPiISR(HORN_INT_GPIO, INT_EDGE_BOTH, &myISRHandler);
//}

