#include "mb_thread.h"
#include <QtCore>
#include <QDebug>

#include <QVector3D>
#include <QMatrix>


MB_Thread::MB_Thread(QObject *parent) :
    QThread(parent)
{
}


int MB_Thread::converges(int x, int y)
{

    auto vec = QVector3D(x - 500, y - 500, 0);
    auto bob = vec / 500 * 2.5;

    auto c = std::complex<double>(
                bob.x() ,
                bob.y());


    //std::complex<double> z_0 = 0 + 0i;

    int n = buffer[x][y];
    std::complex<double> z = previous[x][y];

    if(n < 50 && abs(z) < 4.0){

        z = pow(z, exponent) + c;
        n += 1;
    }

    depth = (depth < n) ? n : depth;

/*
    while(abs(z) < 2.0 && n <= depth){
        z = pow(z, exponent) + c;
        n += 1;
    }*/


    //SAVE INTERMEDIATE VALUES:
    buffer[x][y] = n;
    previous[x][y] = z;

    return n;

}

void MB_Thread::setExponent(float exp)
{
    depth = 1;
    for(int x = 0; x < 1000; x++) {
        for(int y = 0; y < 1000; y++){
            previous[x][y] = std::complex<double>(0,0);
            buffer[x][y] = 0;
        }
    }

    this->exponent = exp;
}

void MB_Thread::run(){
    while(true) {
        for(int x = 0; x < 1000; x++) {
            for(int y = 0; y < 1000; y++){
                converges(x, y);
            }
        }

        //TODO Check if program should exit.

        QMutex mutex;
        mutex.lock();
        if(false) break;
        mutex.unlock();

    }
}
