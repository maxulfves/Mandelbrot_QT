#include "mb_thread.h"
#include <QtCore>
#include <QDebug>

#include <QVector3D>
#include <QVector2D>

#include <QMatrix>


void MB_Thread::stop()
{
    should_exit = true;
}

void MB_Thread::reset()
{
    depth = 1;
    for(int x = 0; x < 1000; x++) {
        for(int y = 0; y < 1000; y++){
            previous[x][y] = std::complex<double>(0,0);
            buffer[x][y] = 0;
        }
    }

}

void MB_Thread::scrollIn(int degree)
{

    reset();

    if(degree > 0){
        zoom *= 0.99;
    }else{
        zoom *= 1.01;
    }

    //qDebug() << "Zoom: " << zoom << degree;
}

MB_Thread::MB_Thread(QObject *parent) : QThread(parent){ }


int MB_Thread::converges(int x, int y)
{
    QMatrix mat;
    mat.scale(1.0/500, 1.0/500);
    mat.scale(zoom, zoom);

    //The pixel coordinate. (-500, -500) to (500, 500)
    auto vec = QVector3D(x - 500 + translation.x(), y - 500 + translation.y(), 0);

    if(x == 0 && y == 0){
        qDebug() << vec;
    }

    //The complex coordinate. Is defined by the amount of zoom, starting at (-2.5, -2.5) to (2.5, 2.5)
    auto bob = (vec) * mat;
    //auto bob = vec / 500 * zoom;


    auto c = std::complex<double>(
                bob.x() ,
                bob.y());

    int n = buffer[x][y];
    std::complex<double> z = previous[x][y];

    if(n < 50 && abs(z) < 2.0){
        z = pow(z, exponent) + c;
        n += 1;
    }

    depth = (depth < n) ? n : depth;

    //SAVE INTERMEDIATE VALUES:

    QRgb value = qRgb(0, n * (255.0/depth), 0);
    image.setPixel(x, y, value);


    buffer[x][y] = n;
    previous[x][y] = z;

    return n;

}


void MB_Thread::setExponent(float exp)
{
    reset();
    this->exponent = exp;
}

void MB_Thread::arrowPress(int key)
{
    reset();
    qDebug() << translation;

    switch (key) {
    case Qt::Key::Key_Left :
        translation.setX(translation.x() - 1);
        break;
    case Qt::Key::Key_Right:
        translation.setX(translation.x() + 1);
        break;
    case Qt::Key::Key_Up:
        translation.setY(translation.y() + 1);
        break;
    case Qt::Key::Key_Down:
        translation.setY(translation.y() - 1);
        break;
    default:
        qDebug() << "?";
    }

}

void MB_Thread::run() {
    while(!should_exit) {

        do{
            for(int x = 0; x < 1000; x++) {
                for(int y = 0; y < 1000; y++){
                    converges(x, y);
                }
            }
        }while(depth < 2);

    }

    is_done = true;
}
