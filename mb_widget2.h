#ifndef MB_WIDGET2_H
#define MB_WIDGET2_H

#include <QWidget>
#include <QPainter>
#include <QtMath>

#include <QMatrix>
#include <QMatrix4x4>

#include <QVector3D>
#include <QVector2D>
#include <QVector>
#include <complex>

#include <mb_thread.h>
#include <QMouseEvent>

class MB_Widget2 : public QWidget
{
    Q_OBJECT
public:
    explicit MB_Widget2(QWidget *parent = nullptr);
    void setExponent(float value);
    void start();
    void updatePixel(int, int, int);
    MB_Thread *myThread;
protected:
    void paintEvent(QPaintEvent *) override;
    void mouseMoveEvent(QMouseEvent *) override;
    void mouseReleaseEvent(QMouseEvent *) override;
private:
    bool converges(std::complex<double> c);
    float exponent = 2.0f;
    int m_canvas[1000][1000];

    int m_x = 250;
    int m_y = 250;

private slots:

signals:
    void NumberChanged(double, double);

};

#endif // MB_WIDGET2_H
