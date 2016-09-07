#include "parser.h"

Parser::Parser()
{

}

QVector<Vertex> Parser::loadOBJ(QString path, QVector<QVector3D> &vertices, QVector<uint> &indices, QVector<QVector2D> &UV, QVector<QVector3D> &norm)
{
    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile(path.toStdString(), aiProcessPreset_TargetRealtime_MaxQuality | aiProcess_FlipUVs);

    /* Catch Assimp Error */
    if(!scene || scene->mFlags ==  AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        qDebug() << "Assimp Error";
    }

    /* Check All Nodes */
    QVector<Vertex> vertex;
    processNode(scene->mRootNode, scene, vertices, indices, UV, norm, vertex);
    return vertex;
}

void Parser::processNode(aiNode *node, const aiScene *scene, QVector<QVector3D> &vert, QVector<uint> &ind, QVector<QVector2D> &UV, QVector<QVector3D> &norm, QVector<Vertex> &vertex)
{
    for(uint i = 0; i < node->mNumMeshes; i++) {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        vertex.push_back(processMesh(mesh, scene, vert, ind, UV, norm));
    }

    for(uint i = 0; i < node->mNumChildren; i++) {
        processNode(node->mChildren[i], scene, vert, ind, UV, norm, vertex);
    }
}

Vertex Parser::processMesh(aiMesh* mesh, const aiScene* scene, QVector<QVector3D> &vert, QVector<uint> &ind, QVector<QVector2D> &UV, QVector<QVector3D> &norm)
{
    /* Clear Previous data */
    vert.clear();
    ind.clear();
    UV.clear();
    norm.clear();

    for(uint i = 0; i < mesh->mNumVertices; i++) {

        /* Position */
        vert.push_back(QVector3D(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z));

        /* Normals */
        norm.push_back(QVector3D(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z));

        /* Texture Coordinates */
        if(mesh->mTextureCoords[0]) {
            UV.push_back(QVector2D(mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y));
        } else {
           UV.push_back(QVector2D(0, 0));
        }
    }

    /* Vertex Indices */
    for(uint i = 0; i < mesh->mNumFaces; i++) {
        aiFace face = mesh->mFaces[i];
        /* Retrieve all indices of the face and store them in the indices vector */
        for(uint j = 0; j < face.mNumIndices; j++)
            ind.push_back(face.mIndices[j]);
    }

    return Vertex(vert, ind, UV, norm);
}
