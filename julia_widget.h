#ifndef JULIA_WIDGET_H
#define JULIA_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtMath>

#include <QMatrix>
#include <QMatrix4x4>

#include <QVector3D>
#include <QVector2D>
#include <QVector>
#include <complex>

#include <jl_thread.h>


class Julia_Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Julia_Widget(QWidget *parent = nullptr);
    void setExponent(float value);
    void start();
    void updatePixel(int, int, int);
    JL_Thread *myThread;
protected:
    void paintEvent(QPaintEvent *) override;

private:
    bool converges(std::complex<double> c);
    float exponent = 2.0f;
    int m_canvas[1000][1000];


};

#endif // JULIA_WIDGET_H
