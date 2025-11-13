#include "circuitbutton.h"

CircuitButton::CircuitButton(QObject *parent)
    : QObject{parent}
{
    hornTimer = new QTimer(this);
    hornTimer->setInterval(1);
    connect(hornTimer, &QTimer::timeout, this, &MainWindow::carHorn);


}
