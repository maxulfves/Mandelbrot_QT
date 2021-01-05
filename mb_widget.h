#ifndef MB_WIDGET_H
#define MB_WIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QtOpenGL>

class MB_Widget : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT
public:
    MB_Widget(QWidget *parent = nullptr);
    void setExponent(float value);
protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
private:
    //void qColorToRGB(const QColor &C, float &r, float &g, float &b);
    float exponent = 2.0f;
};

#endif // MB_WIDGET_H
