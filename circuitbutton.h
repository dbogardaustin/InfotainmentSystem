#ifndef CIRCUITBUTTON_H
#define CIRCUITBUTTON_H

#include <QObject>

class CircuitButton : public QObject
{
    Q_OBJECT
public:
    explicit CircuitButton(QObject *parent = nullptr);
    explicit CircuitButton(QObject *parent = nullptr, int gpioPin = 0);
    void onButtonPress();
    void onButtonRelease();
    int getGpioPin();

private:
    int gpioPin;

signals:
    void buttonPressed();
    void buttonReleased();

};

#endif // CIRCUITBUTTON_H
