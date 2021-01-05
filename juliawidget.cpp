#include "juliawidget.h"

JuliaWidget::JuliaWidget(QWidget *parent) : QOpenGLWidget{ parent } {

}

void JuliaWidget::initializeGL() {

    QColor qcol = QColor(1,2,3);

    initializeOpenGLFunctions();
    glClearColor(0.5f, 1.0f, 1.0f, 1.0f);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    //glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);


}

void JuliaWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void JuliaWidget::resizeGL(int w, int h) {
    /*
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();*/
}

void qColorToRGB(const QColor &C, float &r, float &g, float &b){
    int red = C.red();
    int green = C.green();
    int blue = C.blue();

}
