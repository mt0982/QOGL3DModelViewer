#ifndef PARSER_H
#define PARSER_H

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <cassert>
#include <QVector>
#include <QVector2D>
#include <QVector3D>
#include <QDebug>

struct Vertex {
    QVector<QVector3D> vertices;
    QVector<uint> indices;
    QVector<QVector2D> UV;
    QVector<QVector3D> normals;

    Vertex(){}
    Vertex(QVector<QVector3D> v, QVector<uint> i, QVector<QVector2D> u): vertices(v), indices(i), UV(u){}
    Vertex(QVector<QVector3D> v, QVector<uint> i, QVector<QVector2D> u, QVector<QVector3D> n): vertices(v), indices(i), UV(u), normals(n){}
};

class Parser {
public:
    Parser();
    QVector<Vertex> loadOBJ(QString path, QVector<QVector3D> &vertices, QVector<uint> &indices, QVector<QVector2D> &UV, QVector<QVector3D> &norm);
    void processNode(aiNode *node, const aiScene *scene, QVector<QVector3D> &vert, QVector<uint> &ind, QVector<QVector2D> &UV, QVector<QVector3D> &norm, QVector<Vertex> &Vertex);
    Vertex processMesh(aiMesh *mesh, const aiScene *scene, QVector<QVector3D> &vert, QVector<uint> &ind, QVector<QVector2D> &UV, QVector<QVector3D> &norm);
};

#endif // PARSER_H
