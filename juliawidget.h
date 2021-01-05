#ifndef JULIA_WIDGET_H
#define JULIA_WIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>


class JuliaWidget : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT
public:
    JuliaWidget(QWidget *parent = nullptr);

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
private:
    void qColorToRGB(const QColor &C, float &r, float &g, float &b);

};

#endif // MB_WIDGET_H
