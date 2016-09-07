#version 450

in vec3 baseColor;
in vec3 fragPosition;
in vec2 UV;
in vec3 N, T;

uniform vec3 cameraPosition;
uniform vec3 lightPosition;
uniform sampler2D diffuseMap;
uniform sampler2D normalMap;

out vec4 outColor;

vec3 CalcBumpedNormal()
{
    vec3 norm = normalize(N);
    vec3 Tangent = normalize(T);
    Tangent = normalize(Tangent - dot(Tangent, norm) * norm);
    vec3 Bitangent = cross(Tangent, norm);
    vec3 BumpMapNormal = texture2D(normalMap, UV).xyz;
    BumpMapNormal = 2.0 * BumpMapNormal - vec3(1.0, 1.0, 1.0);
    vec3 NewNormal;
    mat3 TBN = mat3(Tangent, Bitangent, norm);
    NewNormal = TBN * BumpMapNormal;
    NewNormal = normalize(NewNormal);
    return NewNormal;
}

void main(void)
{
    /* Color */
    vec3 color = texture2D(diffuseMap, UV).xyz; //baseColor;

    /* Normals */
    vec3 normal = CalcBumpedNormal();

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
