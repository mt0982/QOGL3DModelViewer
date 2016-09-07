#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLFunctions_4_5_Core>
#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <QOpenGLFramebufferObject>
#include <QOpenGLFramebufferObjectFormat>
#include <QOpenGLTexture>
#include <QVector>
#include <QVector2D>
#include <QVector3D>
#include <QMatrix3x3>
#include <QMatrix4x4>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QTime>
#include <QTimer>
#include <mesh.h>
#include <Interaction/camera.h>
#include <Interaction/menu.h>
#include <Loader/modelloader.h>

class GLWidget: public QOpenGLWidget, protected QOpenGLFunctions_4_5_Core
{
private:
    Q_OBJECT
    QMatrix4x4 MVMat, ProjMat;
    QTimer timer;
    QTime time;
    Camera camera;

    int fps;

    QOpenGLShaderProgram program;
    ModelLoader modelLoader;

    QVector3D lightPosition;

    Menu *menu;

public:
    explicit GLWidget(QWidget *parent = 0);
    ~GLWidget();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void mouseMoveEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e);

private slots:
    void redraw();
};

#endif // GLWIDGET_H





















