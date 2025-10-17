#ifndef INTERIORLIGHTS_H
#define INTERIORLIGHTS_H

#include <QDialog>
#include "wiringPi.h"

namespace Ui {
class InteriorLights;
}

class InteriorLights : public QDialog
{
    Q_OBJECT

public:
    explicit InteriorLights(QWidget *parent = nullptr);
    ~InteriorLights();

private slots:
    void on_pushButton_clicked();

    void on_Front_stateChanged(int arg1);

    void on_Mid_stateChanged(int arg1);

    void on_Back_stateChanged(int arg1);

    void on_resetButton_clicked();

private:
    Ui::InteriorLights *ui;
};

#endif // INTERIORLIGHTS_H
