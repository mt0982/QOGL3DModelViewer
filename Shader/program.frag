#version 450

in vec3 baseColor;
in vec3 fragPosition;
in vec3 N;

uniform vec3 cameraPosition;
uniform vec3 lightPosition;

out vec4 outColor;

void main(void)
{
    //outColor = vec4(baseColor, 1.0);

    /* Color */
    vec3 color = baseColor;

    /* Normals */
    vec3 normal = N;

    /* Ambient */
    vec3 ambient = 0.35 * color;

    /* Diffuse */
    vec3 lightDir = normalize(lightPosition - fragPosition);
    float diff = max(dot(lightDir, normal), 0.0);
    vec3 diffuse = diff * color;

    /* Specular */
    vec3 viewDir = normalize(cameraPosition - fragPosition);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = 0.0;
    vec3 halfwayDir = normalize(lightDir + viewDir);
    spec = pow(max(dot(normal, halfwayDir), 0.0), 32.0);
    vec3 specular = vec3(0.3) * spec;

    outColor = vec4(ambient + diffuse + specular, 1.0);
}
