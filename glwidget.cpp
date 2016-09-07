#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent): QOpenGLWidget(parent)
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(redraw()));
    timer.start(1.0f);
    time.start();
    lightPosition = QVector3D(0, 2, 1);

    /* Show Menu */
    menu = new Menu;
    menu->show();
}

GLWidget::~GLWidget()
{
    makeCurrent();
    doneCurrent();
}

void GLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);

    program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/Shader/program.vert");
    program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/Shader/program.frag");
    program.link();

    /* Init Model Loader */
    modelLoader.init(program);

    /* Texture */
    modelLoader.setDiffuseMap("/home/asus/Programy/Qt/Projekty/QOGL3DModelViewer/Example/Imrod/Imrod_Diffuse.jpg");
    modelLoader.setNormalMap("/home/asus/Programy/Qt/Projekty/QOGL3DModelViewer/Example/Imrod/Imrod Normal.jpg");
    modelLoader.setAmbientMap("/home/asus/Programy/Qt/Projekty/QOGL3DModelViewer/Example/Imrod/Imrod_Ambient.jpg");
    modelLoader.setSpecularMap("/home/asus/Programy/Qt/Projekty/QOGL3DModelViewer/Example/Imrod/Imrod_Specular.jpg");
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    MVMat = camera.getWorldToViewMatrix();

    /* Light Parameters */
    float angle = menu->getAngle();
    float radius = 2;
    float x = cos(angle * 3.141592 / 180.0) * radius;
    float z = sin(angle * 3.141592 / 180.0) * radius;
    lightPosition = QVector3D(x, 1, z);

    /* Render Object */
    modelLoader.render(MVMat, ProjMat, camera.getPosition(), lightPosition, program);
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    ProjMat.setToIdentity();
    ProjMat.perspective(60, (float)w/h, 0.01f, 100.0f);

    menu->setWindowPosition(w,h);
}

void GLWidget::mouseMoveEvent(QMouseEvent *e)
{
    camera.mouseUpdate(QVector2D(e->x(), e->y()));
}

void GLWidget::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_W:
        camera.moveForward();
        break;
    case Qt::Key_A:
        camera.moveLeft();
        break;
    case Qt::Key_S:
        camera.moveBackward();
        break;
    case Qt::Key_D:
        camera.moveRight();
        break;
    case Qt::Key_Space:
        camera.moveUp();
        break;
    case Qt::Key_X:
        camera.moveDown();
        break;
    default:
        break;
    }
}

void GLWidget::redraw()
{
    update();
    if((fps % 100) == 0) {
        setWindowTitle("FPS: " + QString::number(100 /*klatek*/ * 1000 /*milisekund*/ / time.elapsed()));
        time.restart();
    }
    fps++;
}














