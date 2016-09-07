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
    QVector<QVector2D> UV;
    QVector<uint> indices;

    /* Load Object */
    QVector<Vertex> vertex = loadOBJ("/home/asus/Pulpit/untitled3.obj", vertices, indices, UV, normals);
    qDebug() << vertex[0].vertices.size() << vertex[0].indices.size() << vertex[0].normals.size();

    /* Colors */
    for(int i = 0; i < vertices.size(); i++) {
        colors.push_back(QVector3D(0.3, 0.4, 0.35));
    }

    /* Set Attribute */
    model.init();
    model.setAttribute(0, vertices, program);
    model.setAttribute(1, colors, program);
    model.setAttribute(2, normals, program);
    model.setAttribute(3, UV, program);
    model.setIndices(indices);
}

void ModelLoader::render()
{
    model.render();
}















