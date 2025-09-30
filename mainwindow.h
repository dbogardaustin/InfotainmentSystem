#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "about.h"
#include "brightnesscontrol.h"
#include "interiorlights.h"
#include <QMainWindow>

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
    void on_headlights_clicked();

    void on_about_clicked();

    void on_brightnessControl_clicked();

    void on_interiorLights_clicked();

private:
    Ui::MainWindow *ui;
    About *about;
    BrightnessControl *brightnessControl;
    InteriorLights *interiorLights;
};
#endif // MAINWINDOW_H
