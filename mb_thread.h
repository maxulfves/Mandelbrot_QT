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
#include <QImage>

class MB_Thread : public QThread
{
    Q_OBJECT
public:

    explicit MB_Thread(QObject *parent = 0);

    /// Stops the thread.
    void stop();

    /// Sets buffers and variables back to default values. Used when some parameter of the set is updated.
    void reset();

    /// Zooms in or out depending of the sign of the argument. CURRENTLY UNIMPLEMENTED!
    void scrollIn(int degree);


    double exponent = 2.0; // TODO: Make private.
    void run();

    /// Updates the depth of the given pixel by 1.
    int converges(int, int);

    /// Sets the exponent of the MB-set.
    void setExponent(float);

    ///The complex values of the pixel stored.
    std::complex<double> previous[1000][1000];

    /// The depth of the complete picture.
    int depth = 1;

    /// Flag for when the thread has completed it's loop.
    bool is_done = false;

    /// The rendered image of the thread.
    QImage image = QImage(1000, 1000, QImage::Format_RGB32);

    /// Action after arrow is pressed.
    void arrowPress(int);

private:
    ///Maximum depth of render
    const int maxDepth = 50;

    /// Translation of the mb set.
    QVector2D translation = QVector2D(0, 0);

    /// Stores the depth values of each pixel.
    int buffer[1000][1000];

    /// Flag for if the loop should break.
    bool should_exit = false;

    /// Current scale value of the set. Ambiguous?
    float zoom = 2.5f;

signals:
    /// LEGACY
    void NumberChanged(int, int); //Legacy

public slots:
};

#endif // MB_THREAD_H
