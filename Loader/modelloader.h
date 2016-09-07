#ifndef MODELLOADER_H
#define MODELLOADER_H

#include <mesh.h>
#include <QVector3D>
#include <QVector2D>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <Loader/parser.h>

class ModelLoader: public Parser {
private:
    Mesh model;
    QOpenGLTexture *diffuseMap;
    QOpenGLTexture *normalMap;
    QOpenGLTexture *ambientMap;
    QOpenGLTexture *specularMap;
    QString modelPath;

    bool isDiffuse;
    bool isNormal;
    bool isAmbient;
    bool isSpecular;

    QString path;

public:
    ModelLoader();
    void init(QOpenGLShaderProgram &program);
    void render(QMatrix4x4 MVMat, QMatrix4x4 ProjMat, QVector3D eyePos, QVector3D lightPos, QOpenGLShaderProgram &p);

    /* Setters */
    void setDiffuseMap(QString path);
    void setNormalMap(QString path);
    void setAmbientMap(QString path);
    void setSpecularMap(QString path);
    void setFilePath(QString path, bool flag, QOpenGLShaderProgram &program);
};

#endif // MODELLOADER_H


















