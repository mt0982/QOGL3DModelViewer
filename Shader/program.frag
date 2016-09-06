#version 450

in vec3 baseColor;
out vec4 outColor;

void main(void)
{
    outColor = vec4(baseColor, 1.0);
}
