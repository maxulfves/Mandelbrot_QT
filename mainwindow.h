#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "mb_thread.h"
#include "jl_thread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    MB_Thread *myThread;
    JL_Thread *jlThread;

private slots:
    void on_horizontalSlider_valueChanged(int value);
    void clickedGraph(QMouseEvent *ev);
public slots:
    void onNumberChanged(double, double);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
