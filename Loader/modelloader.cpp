#include "modelloader.h"

void parse(QVector<QVector3D> &vertices, QVector<QVector3D> &normals, QVector<uint> &indices)
{
    /* Temporary Variable */
    QVector<QVector3D> temp_normals;
    QVector<QVector2D> temp_uv;
    QVector<uint> normalIndices;

    /* File */
    ifstream in("/home/asus/Pulpit/untitled3.obj", ios::in);
    if (!in) {
        qDebug() << "Cannot open OBJ file";
    }

    string line;
    while(getline(in, line)) {

        /* Vertices */
        if (line.substr(0,2) == "v ") {
            istringstream s(line.substr(2));
            QVector3D v; s >> v[0]; s >> v[1]; s >> v[2];
            vertices.push_back(v);
        }

        /* Normals */
        else if (line.substr(0,3) == "vn ") {
            istringstream s(line.substr(2));
            QVector3D n; s >> n[0]; s >> n[1]; s >> n[2];
            temp_normals.push_back(n);
        }

        /* UV */
        else if (line.substr(0,3) == "vt ") {
            istringstream s(line.substr(2));
            QVector2D n; s >> n[0]; s >> n[1];
            temp_uv.push_back(n);
        }

        /* Indices */
        else if (line.substr(0,2) == "f ") {
            int vx, vy, vz, nx, ny, nz, uvx, uvy, uvz;

            const char *chh = line.c_str();
            sscanf(chh, "f %d/%d/%d %d/%d/%d %d/%d/%d", &vx, &uvx, &nx, &vy, &uvy, &ny, &vz, &uvz, &nz);

            /* Important. Blender indexing from 1 */
            vx--;  vy--;   vz--;
            nx--;  ny--;   nz--;
            uvx--; uvy--;  uvz--;

            /* Vertex Indices */
            indices.push_back(vx);
            indices.push_back(vy);
            indices.push_back(vz);

            /* Normal Indices */
            normalIndices.push_back(nx);
            normalIndices.push_back(ny);
            normalIndices.push_back(nz);
        }
    }

    /* Processing Data */
    for(int i = 0; i < normalIndices.size(); i++) {
        uint index = normalIndices[i];
        normals.push_back(temp_normals[index]);
    }

    qDebug() << vertices.size(); //temp_uv.size();
}

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

    /* Indices | Vertices */
    //model.parseOBJ(vertices, indices);
    parse(vertices, normals, indices);

    qDebug() << vertices.size() << indices.size() << normals.size();

    /* Colors */
    for(int i = 0; i < vertices.size(); i++) {
        colors.push_back(QVector3D(0.3, 0.4, 0.35));
    }

    /* Normals */
    /*normals.clear();
    normals.resize(vertices.size());
    model.calculateNormals(vertices, normals, indices);*/

    /* Set Attribute */
    model.init();
    model.setAttribute(0, vertices, program);
    model.setAttribute(1, colors, program);
    model.setAttribute(2, normals, program);
    model.setIndices(indices);
}

void ModelLoader::render()
{
    model.render();
}















