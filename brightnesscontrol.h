#ifndef BRIGHTNESSCONTROL_H
#define BRIGHTNESSCONTROL_H

#include <QDialog>

namespace Ui {
class BrightnessControl;
}

class BrightnessControl : public QDialog
{
    Q_OBJECT

public:
    explicit BrightnessControl(QWidget *parent = nullptr);
    ~BrightnessControl();

private slots:
    void on_pushButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_brightButton_clicked();

    void on_dimButton_clicked();

private:
    Ui::BrightnessControl *ui;
};

#endif // BRIGHTNESSCONTROL_H
