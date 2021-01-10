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
#include <QImage>

class JL_Thread : public QThread
{
    Q_OBJECT

public:
    /// The constructor
    explicit JL_Thread(QObject *parent = 0);

    /// Breaks the thread's loop.
    void stop();


    double exponent = 2.0;

    void run();

    /// Sets the exponent of the Julia-set.
    void setExponent(float);

    /// Sets the Z_0 of the Julia-set.
    void setZ_0(std::complex<double>);

    /// A bufer for the earlier complex values.
    std::complex<double> previous[1000][1000];

    /// Depth of the simulation. Starting at 1.
    int depth = 1;

    /// Flag for when the thread has finnished executing.
    bool is_done = false;

    /// The rendered image.
    QImage image = QImage(1000, 1000, QImage::Format_RGB32);


private:
    ///Maximum depth of render
    const int maxDepth = 50;

    /// Updates a given pixel by one step.
    int converges(int, int);

    /// Stores the depth of each pixel.
    int buffer[1000][1000];

    /// Starting value of the julia-set. (LEGACY)
    std::complex<double> z_0 = 0;

    /// Resets the set. Sets all buffers and depth to initial values.
    void reset();

    /// Flag for wether something has changed.
    bool changed = false;

    /// Flag for when the while loop should break.
    bool should_exit = false;
signals:
    /// LEGACY. Detects when a pixel is changed.
    void NumberChanged(int, int, int);

public slots:
};

#endif // JL_THREAD_H
