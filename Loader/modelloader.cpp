#include "modelloader.h"

ModelLoader::ModelLoader()
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

void ModelLoader::render()
{
    model.render();
}















