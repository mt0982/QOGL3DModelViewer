#include "modelloader.h"

ModelLoader::ModelLoader()
{

}

void ModelLoader::init(QOpenGLShaderProgram &program)
{
    float s = 0.1;
    QVector<QVector3D> vertices;// = {{-s, -s, 0}, {s, -s, 0}, {s, s, 0}, {-s, s, 0}};
    QVector<QVector3D> colors;// = {{0.2, 0.3, s}, {0.7, 0.3, 0.7}, {0.5, 0.4, s}, {0.9, 0.8, 0.3}};
    QVector<uint> indices;// = {0, 1, 2, 0, 2, 3};

    model.parseOBJ(vertices, indices);

    for(int i = 0; i < vertices.size(); i++) {
        colors.push_back(QVector3D(0.3, 0.4, 0.7));
    }

    model.init();
    model.setAttribute(0, vertices, program);
    model.setAttribute(1, colors, program);
    model.setIndices(indices);
}

void ModelLoader::render()
{
    model.render();
}
