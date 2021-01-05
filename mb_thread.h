#ifndef MB_THREAD_H
#define MB_THREAD_H

#include <QtCore>
#include <QThread>
#include <QtMath>
#include <QMatrix>
#include <QMatrix4x4>

#include <QVector3D>
#include <QVector2D>
#include <QVector>
#include <complex>

class MB_Thread : public QThread
{
    Q_OBJECT
public:
    explicit MB_Thread(QObject *parent = 0);

    double exponent = 2.0;
    void run();
    int converges(int, int);

    void setExponent(float);



    int buffer[1000][1000];
    std::complex<double> previous[1000][1000];
    int depth = 1;

private:


signals:
    void NumberChanged(int, int);

public slots:
};

#endif // MB_THREAD_H
