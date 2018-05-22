#version 330 core

in vec3 vertex;
in vec3 normal;

in vec3 matamb;
in vec3 matdiff;
in vec3 matspec;
in float matshin;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 TG;

uniform vec3 colFocus;
uniform vec4 posFocus;
uniform vec3 llumAmbient;

out vec3 fcolor;

out vec3 matamb1;
out vec3 matdiff1;
out vec3 matspec1;
out float matshin1;

out vec3 L1;
out vec4 vertexSCO1;
out vec3 NormSCO1;

void main()
{   
    fcolor = matdiff;
    gl_Position = proj * view * TG * vec4 (vertex, 1.0);

    matamb1 = matamb;
    matdiff1 = matdiff;
    matspec1 = matspec;
    matshin1 = matshin;
    fcolor = matdiff;

    L1 = vec3(posFocus - vertexSCO1);
    NormSCO1 = inverse(transpose(mat3(view * TG))) * normal;
    vertexSCO1 = view * TG * vec4(vertex,1.0);
}
