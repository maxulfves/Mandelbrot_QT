#ifndef JULIA_WIDGET_H
#define JULIA_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtMath>

#include <QMatrix>
#include <QMatrix4x4>

#include <QVector3D>
#include <QVector2D>
#include <QVector>
#include <complex>

#include <jl_thread.h>


class Julia_Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Julia_Widget(QWidget *parent = nullptr);

    /// Starts the thread
    void start();


    JL_Thread *myThread; // TODO: Make private.
protected:
    void paintEvent(QPaintEvent *) override;

private:

};

#endif // JULIA_WIDGET_H
