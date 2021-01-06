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
    myThread->stop();
    jlThread->stop();

    //TODO: Find out what the correct way of closing is. This looks ridiculous.
    while(!myThread->is_done || !jlThread->is_done){
    }

    delete ui;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    float exponent = (float)value / 10.0;

    myThread->setExponent(exponent);
    jlThread->setExponent(exponent);

    //ui->mandelbrot_widget->update();


}

void MainWindow::clickedGraph(QMouseEvent *ev)
{
    //qDebug() << ev->pos();
}

void MainWindow::onNumberChanged(double x, double y){
    //ui->mandelbrot_widget->updatePixel(x, y, n);

    auto bob = std::complex<double>(x, y);
    jlThread->setZ_0(bob);
}



void MainWindow::on_actionExit_triggered()
{
    QCoreApplication::quit();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("This program was Developed by Max Ulfves in the winter of 2021");
    msgBox.exec();
}

void MainWindow::on_actionTutorial_triggered()
{
    QMessageBox msgBox;
    msgBox.setText(
                "Use the slider to change the exponent of the Multibrot. \nClick on the multibrot to choose the starting complex number of the Julia-set. \nNot that much else to it. =)"
    );
    msgBox.exec();
}
