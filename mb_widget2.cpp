#include "mb_widget2.h"

MB_Widget2::MB_Widget2(QWidget *parent) : QWidget(parent)
{

}




void MB_Widget2::paintEvent(QPaintEvent *)
{
    //Setup QPainter
    QPainter painter(this);
    painter.setPen(Qt::blue);

    for(int x = 0; x < 500; x++){
        for(int y = 0; y < 500; y++){

            painter.setPen(QColor(
                    0,
                    myThread->buffer[x*2][y*2] * (255.0/myThread->depth),
                    myThread->buffer[x*2][y*2] * (255.0/myThread->depth),
                    255));


            if(myThread->buffer[x * 2][y* 2] ){
                painter.drawPoint(x, y);
            }
        }
    }

    painter.setPen(QColor(255, 0, 0, 255));
    //painter.drawLine(0, 0, 100, 100);

    //qDebug() << m_x << "/" << m_y;
    painter.drawEllipse(m_x - 2, m_y - 2, 4, 4);

    update();

}

void MB_Widget2::mouseMoveEvent(QMouseEvent *event)
{
    auto pos = event->pos();
    m_x = (pos.x());
    m_y = (pos.y());
}

void MB_Widget2::mouseReleaseEvent(QMouseEvent *event)
{
    auto pos = event->pos();

    m_x = (pos.x());
    m_y = (pos.y());

    emit NumberChanged(
                (m_x - 250)/500.0 * 2.5,
                (m_y - 250)/500.0 * 2.5
                );
}


