#ifndef CIRCUITBUTTON_H
#define CIRCUITBUTTON_H

#include <QObject>
#include <QTimer>

class CircuitButton : public QObject
{
    Q_OBJECT
public:
    explicit CircuitButton(QObject *parent = nullptr);
    explicit CircuitButton(QObject *parent = nullptr, int gpioPin = 0);

    QTimer *hornTimer;

signals:
    void buttonPressed();
    void buttonReleased();

private:
    void onButtonPress();
    void onButtonRelease();
};

#endif // CIRCUITBUTTON_H
