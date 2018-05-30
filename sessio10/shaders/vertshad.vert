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

uniform vec3 colFocus2;
uniform vec4 posFocus2;
uniform vec3 llumAmbient2;

// Valors per als components que necessitem dels focus de llum
vec3 colFocus = vec3(0.8, 0.8, 0.8);
vec3 llumAmbient = vec3(0.2, 0.2, 0.2);
vec3 posFocus = vec3(1, 1, 1);  // en SCA


out vec3 matamb1;
out vec3 matdiff1;
out vec3 matspec1;
out float matshin1;
out vec3 L1;
out vec4 vertexSCO1;
out vec3 fcolor;
out vec3 NormSCO1;

vec3 Lambert (vec3 NormSCO, vec3 L) 
{
    // S'assumeix que els vectors que es reben com a paràmetres estan normalitzats

    // Inicialitzem color a component ambient
    vec3 colRes = llumAmbient2 * matamb;

    // Afegim component difusa, si n'hi ha
    if (dot (L, NormSCO) > 0)
      colRes = colRes + colFocus2 * matdiff * dot (L, NormSCO);
    return (colRes);
}

vec3 Phong (vec3 NormSCO, vec3 L, vec4 vertSCO) 
{
    // Els vectors estan normalitzats

    // Inicialitzem color a Lambert
    vec3 colRes = Lambert (NormSCO, L);

    // Calculem R i V
    if (dot(NormSCO,L) < 0)
      return colRes;  // no hi ha component especular

    vec3 R = reflect(-L, NormSCO); // equival a: normalize (2.0*dot(NormSCO,L)*NormSCO - L);
    vec3 V = normalize(-vertSCO.xyz);

    if ((dot(R, V) < 0) || (matshin == 0))
      return colRes;  // no hi ha component especular
    
    // Afegim la component especular
    float shine = pow(max(0.0, dot(R, V)), matshin);
    return (colRes + matspec * colFocus * shine); 
}

void main()
{	

    matamb1 = matamb;
    matdiff1 = matdiff;
    matspec1 = matspec;
    matshin1 = matshin;
    //fcolor = color;
    fcolor = matdiff;

    vec3 L1, NormSCO1;
    vec4 vertexSCO;
    L1 = vec3(posFocus2 - vertexSCO);
    NormSCO1 = inverse(transpose(mat3(view * TG))) * normal;
    vertexSCO1 = view * TG * vec4(vertex,1.0);

    gl_Position = proj * view * TG * vec4 (vertex, 1.0);

    /*vec3 L, lnorm, NormSCOnorm;
    vec4 vertexSCO;

    vertexSCO = view * TG * vec4(vertex,1.0);
    //vec4 posFocusSCO = view * vec4(posFocus, 0.0);
    //L = vec3(posFocusSCO - vertexSCO);

    L = vec3(posFocus2 - vertexSCO);
    vec3 NormSCO = inverse(transpose(mat3(view * TG))) * normal;

    L = normalize(L);
    NormSCO = normalize(NormSCO);

    fcolor = Phong(NormSCO, L, vertexSCO);
    //fcolor = Lambert (NormSCO, L);*/
}
