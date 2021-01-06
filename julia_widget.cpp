#include "julia_widget.h"

Julia_Widget::Julia_Widget(QWidget *parent) : QWidget(parent)
{

}




void Julia_Widget::paintEvent(QPaintEvent *)
{
    //Setup QPainter
    QPainter painter(this);
    painter.setPen(Qt::blue);
/*
    for(int x = 0; x < 500; x++){
        for(int y = 0; y < 500; y++){
            if(myThread){
            painter.setPen(QColor(
                    0,
                    myThread->buffer[x*2][y*2] * (255.0/myThread->depth),
                    myThread->buffer[x*2][y*2] * (255.0/myThread->depth),
                    255));

            painter.drawPoint(x, y);

            }
        }
    }
*/

    QRectF target(0, 0.0, 500.0, 500.0);
    QRectF source(100, 100, 800, 800);
    painter.drawImage(target, myThread->image, source);

    update();

}
