#ifndef JL_THREAD_H
#define JL_THREAD_H


#include <QtCore>
#include <QThread>
#include <QtMath>
#include <QMatrix>
#include <QMatrix4x4>

#include <QVector3D>
#include <QVector2D>
#include <QVector>
#include <complex>

class JL_Thread : public QThread
{
    Q_OBJECT
public:
    explicit JL_Thread(QObject *parent = 0);

    double exponent = 2.0;
    void run();
    int converges(int, int);

    void setExponent(float);

    void setZ_0(std::complex<double>);

    int buffer[1000][1000];
    std::complex<double> previous[1000][1000];
    int depth = 1;

private:
    std::complex<double> z_0 = 0.5 + 0.5i;
    void reset();
    bool changed = false;
signals:
    void NumberChanged(int, int, int);

public slots:
};

#endif // JL_THREAD_H
