#include "circuitbutton.h"
#include <gpioconstants.h>
#include "wiringPi.h"

CircuitButton::CircuitButton(QObject *parent, int gpioPin)
    : QObject{parent}
{
    wiringPiISR(gpioPin, INT_EDGE_RISING, &CircuitButton::onButtonPress);
    wiringPiISR(gpioPin, INT_EDGE_FALLING, &CircuitButton::onButtonRelease);
}


void CircuitButton::onButtonPress() {
    emit buttonPressed();
}

void CircuitButton::onButtonRelease() {
    emit buttonReleased();
}
