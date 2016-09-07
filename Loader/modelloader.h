#ifndef MODELLOADER_H
#define MODELLOADER_H

#include <mesh.h>
#include <QVector3D>
#include <QVector2D>
#include <QOpenGLShaderProgram>
#include <Loader/parser.h>

class ModelLoader: public Parser {
private:
    Mesh model;

public:
    ModelLoader();
    void init(QOpenGLShaderProgram &program);
    void render();
};

#endif // MODELLOADER_H
