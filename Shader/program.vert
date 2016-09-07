#version 450

layout (location = 0) in vec3 VertexPosition;
layout (location = 1) in vec3 VertexColor;
layout (location = 2) in vec3 VertexNormal;
layout (location = 3) in vec2 TextureCoordinates;
layout (location = 4) in vec3 VertexTangent;

uniform mat4 ProjMat;
uniform mat4 MVMat;

out vec3 baseColor;
out vec3 fragPosition;
out vec2 UV;
out vec3 N, T;

void main(void)
{
    gl_Position = ProjMat * MVMat * vec4(VertexPosition, 1.0);
    baseColor = VertexColor;
    fragPosition = VertexPosition;
    UV = TextureCoordinates;
    N = VertexNormal;
    T = VertexTangent;
}
