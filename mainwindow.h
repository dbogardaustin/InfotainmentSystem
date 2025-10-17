#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "about.h"
#include "brightnesscontrol.h"
#include "interiorlights.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_about_clicked();

    void on_brightnessControl_clicked();

    void on_interiorLights_clicked();

    void on_headlights_clicked();

private:
    Ui::MainWindow *ui;
    About *about;
    InteriorLights *interiorLights;
    BrightnessControl *brightnessControl;
};
#endif // MAINWINDOW_H
