#ifndef MB_WIDGET2_H
#define MB_WIDGET2_H

#include <QWidget>
#include <QPainter>
#include <QtMath>

#include <QMatrix>
#include <QMatrix4x4>

#include <QVector3D>
#include <QVector2D>
#include <QVector>
#include <complex>

#include <mb_thread.h>
#include <QMouseEvent>

class MB_Widget2 : public QWidget
{
    Q_OBJECT
public:
    explicit MB_Widget2(QWidget *parent = nullptr);
    void start();

    /// Reference to the thread rendering the MB-set.
    MB_Thread *myThread;
protected:
    // Following functions need no explaination.

    void paintEvent(QPaintEvent *) override;
    void mouseMoveEvent(QMouseEvent *) override;
    void mouseReleaseEvent(QMouseEvent *) override;


private:
    //Todo: make vector.
    /// The x-coord for the cursor.
    int m_x = 250;
    /// The y-coord for the cursor.
    int m_y = 250;

private slots:

signals:
    /// Signal for when the MB-widget has chosen a different Julia-starting value.
    void NumberChanged(double, double);

};

#endif // MB_WIDGET2_H
