#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <complex>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myThread = new MB_Thread(this);
    jlThread = new JL_Thread(this);

    connect(ui->mandelbrot_widget, SIGNAL(NumberChanged(double, double)), this, SLOT(onNumberChanged(double, double)));

    ui->mandelbrot_widget->myThread = myThread;
    ui->julia->myThread = jlThread;

    jlThread->start(QThread::LowestPriority);
    myThread->start(QThread::LowPriority);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    float exponent = (float)value / 10;

    myThread->setExponent(exponent);
    jlThread->setExponent(exponent);
    //ui->mandelbrot_widget->update();


}

void MainWindow::clickedGraph(QMouseEvent *ev)
{
    qDebug() << ev->pos();
}

void MainWindow::onNumberChanged(double x, double y){
    //ui->mandelbrot_widget->updatePixel(x, y, n);

    auto bob = std::complex<double>(x, y);
    jlThread->setZ_0(bob);
}
