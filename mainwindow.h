#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "mb_thread.h"
#include "jl_thread.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /// The thread rendering the Mandelbrot-set.
    MB_Thread *myThread;

    /// The thread rendering the Julia-set.
    JL_Thread *jlThread;

private slots:
    // Following functions need no explaination.

    void on_horizontalSlider_valueChanged(int value);
    void on_actionExit_triggered();
    void on_actionAbout_triggered();

    void on_actionTutorial_triggered();

public slots:
    void onNumberChanged(double, double);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
