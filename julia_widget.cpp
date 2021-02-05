#include "julia_widget.h"

Julia_Widget::Julia_Widget(QWidget *parent) : QWidget(parent)
{

}




void Julia_Widget::paintEvent(QPaintEvent *)
{
    //Setup QPainter
    QPainter painter(this);
    painter.setPen(Qt::blue);

    QRectF target(0, 0.0, 500.0, 500.0);
    QRectF source(100, 100, 800, 800);
    painter.drawImage(target, myThread->image, source);

    update();

}
