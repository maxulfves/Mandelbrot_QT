#include "mb_widget2.h"

MB_Widget2::MB_Widget2(QWidget *parent) : QWidget(parent)
{
    //Empty
}

void MB_Widget2::paintEvent(QPaintEvent *)
{
    //Setup QPainter
    QPainter painter(this);

    //Define rectangles for the projection.
    QRectF target(0, 0, width(), height());
    QRectF source(0, 0, 1000, 1000);

    //Draws the image
    painter.drawImage(target, myThread->image, source);

    //Draws the cursor
    painter.setPen(QColor(255, 0, 0, 255));
    painter.drawEllipse(m_x - 2, m_y - 2, 4, 4);

    //Request and update of the widget
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
                (m_x - 250)/250.0 * 2.5,
                (m_y - 250)/250.0 * 2.5
                );
}


