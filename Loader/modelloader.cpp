#include "modelloader.h"

ModelLoader::ModelLoader(): isDiffuse(false), isNormal(false), isAmbient(false), isSpecular(false)
{

}

void ModelLoader::init(QOpenGLShaderProgram &program)
{
    /* Attribute */
    QVector<QVector3D> vertices;
    QVector<QVector3D> normals;
    QVector<QVector3D> colors;
    QVector<QVector3D> tangents;
    QVector<QVector2D> UV;
    QVector<uint> indices;

    /* Load Object */
    QVector<Vertex> vertex = loadOBJ("/home/asus/Programy/Qt/Projekty/QGLScreenLock/Object/Imrod/ImrodLowPoly.obj", vertices, indices, UV, normals);

    /* Info */
    qDebug() << "Parts:" << vertex.size();
    qDebug() << "Vertices:" << vertex[0].vertices.size();
    qDebug() << "Indices:" << vertex[0].indices.size();
    qDebug() << "Normals:" << vertex[0].normals.size();
    qDebug() << "UVs:" << vertex[0].UV.size();

    /* Colors */
    for(int i = 0; i < vertices.size(); i++) {
        colors.push_back(QVector3D(0.3, 0.4, 0.35));
        vertices[i] /= 50;
    }

    /* Tangents */
    model.calculateTangents(vertices, indices, UV, tangents);

    /* Set Attribute */
    model.init();
    model.setAttribute(0, vertices, program);
    model.setAttribute(1, colors, program);
    model.setAttribute(2, normals, program);
    model.setAttribute(3, UV, program);
    model.setAttribute(4, tangents, program);
    model.setIndices(indices);
}

void ModelLoader::render(QMatrix4x4 MVMat, QMatrix4x4 ProjMat, QVector3D eyePos, QVector3D lightPos, QOpenGLShaderProgram &p)
{
    /* Check Texture */
    if(isDiffuse) {
        diffuseMap->bind(0);

        if(isNormal) normalMap->bind(1);
        if(isAmbient) ambientMap->bind(2);
        if(isSpecular) specularMap->bind(3);
    }

    /* Render */
    p.bind();
    p.setUniformValue("MVMat", MVMat);
    p.setUniformValue("ProjMat", ProjMat);
    p.setUniformValue("cameraPosition", eyePos);
    p.setUniformValue("lightPosition", lightPos);
    p.setUniformValue("diffuse", 0);
    p.setUniformValue("normalMap", 1);
    p.setUniformValue("aoMap", 2);
    p.setUniformValue("specularMap", 3);

    p.setUniformValue("isNormal", isNormal);
    p.setUniformValue("isAmbient", isAmbient);
    p.setUniformValue("isSpecular", isSpecular);

    model.render();
    p.release();
}

void ModelLoader::setDiffuseMap(QString path)
{
    isDiffuse = true;
    diffuseMap = new QOpenGLTexture(QImage(path));
    diffuseMap->setMinificationFilter(QOpenGLTexture::Linear);
    diffuseMap->setMagnificationFilter(QOpenGLTexture::Linear);
}

void ModelLoader::setNormalMap(QString path)
{
    isNormal = true;
    normalMap = new QOpenGLTexture(QImage(path));
}

void ModelLoader::setAmbientMap(QString path)
{
    isAmbient = true;
    ambientMap = new QOpenGLTexture(QImage(path));
}

void ModelLoader::setSpecularMap(QString path)
{
    isSpecular = true;
    specularMap = new QOpenGLTexture(QImage(path));
}















