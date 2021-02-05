#include "jl_thread.h"

#include <QtCore>
#include <QVector3D>
#include <QMatrix>

void JL_Thread::stop()
{
    should_exit = true;
}

JL_Thread::JL_Thread(QObject *parent) :
    QThread(parent)
{
}


int JL_Thread::converges(int x, int y) {

    int n = buffer[x][y];
    std::complex<double> z = previous[x][y];

    if( abs(z) < 2.0 ) {
        z = pow(z, exponent) + z_0;
        n += 1;
    }

    depth = (depth < n) ? n : depth;

    //SAVE INTERMEDIATE VALUES:
    buffer[x][y] = n;
    previous[x][y] = z;

    QRgb value = qRgb(0, n * (255.0/depth), 0);
    image.setPixel(x, y, value);

    return n;
}

void JL_Thread::reset(){
    depth = 1;
    for(int x = 0; x < 1000; x++) {
        for(int y = 0; y < 1000; y++) {
            auto vec = QVector3D(x - 500, y - 500, 0);
            auto bob = vec / 500 * 2.5;
            auto c = std::complex<double>(
                        bob.x() ,
                        bob.y());

            previous[x][y] = c;
            buffer[x][y] = 0;

        }
    }
}

void JL_Thread::setExponent(float exp)
{
    //reset();
    changed = true;
    this->exponent = exp;
}

void JL_Thread::setZ_0(std::complex<double> com ) {
    //reset();
    changed = true;
    z_0.imag(com.imag());
    z_0.real(com.real());

}

void JL_Thread::run(){
    setExponent(2.0);

    while(!should_exit) {

        if(changed){
            changed = false;
            reset();
        }

        #pragma omp parallel for
        for(int xy = 0; xy < 1000*1000; xy++){
            const int x = xy/1000;
            const int y = xy % 1000;

            if(depth < maxDepth){
                converges(x, y);
            }

        }
    }
    is_done = true;
}

