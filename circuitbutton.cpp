#include "circuitbutton.h"

CircuitButton::CircuitButton(QObject *parent, int gpioPin)
    : QObject{parent}
{
    this->gpioPin = gpioPin;
}


void CircuitButton::onButtonPress() {
    emit buttonPressed();
}

void CircuitButton::onButtonRelease() {
    emit buttonReleased();
}

int CircuitButton::getGpioPin() {
    return this->gpioPin;
}
