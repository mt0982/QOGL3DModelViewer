#version 450

layout (location = 0) in vec3 VertexPosition;
layout (location = 1) in vec3 VertexColor;

uniform mat4 ProjMat;
uniform mat4 MVMat;

out vec3 baseColor;

void main(void)
{
    gl_Position = ProjMat * MVMat * vec4(VertexPosition, 1.0);
    baseColor = VertexColor;
}
