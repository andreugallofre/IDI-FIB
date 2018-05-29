#version 330 core

in vec3 vertex;
in vec3 normal;

in vec3 matamb;   //Color
in vec3 matdiff; //Llumn difusa
in vec3 matspec; //Com reflexa
in float matshin; //Llum reflexada

uniform mat4 proj;
uniform mat4 view;
uniform mat4 TG;

uniform vec3 colFocus;
uniform vec4 posFocus;
uniform vec3 llumAmbient;

uniform int test;

out vec3 fcolor;

vec3 matamb1 = vec3(0.3,0.3,0.3);
vec3 matdiff1 = vec3(0.8,0.8,0.8);
vec3 matspec1 = vec3(0.8,0.8,0.8);
float matshin1 = 100;

vec3 Lambert (vec3 NormSCO, vec3 L) 
{
    // S'assumeix que els vectors que es reben com a paràmetres estan normalitzats

    // Inicialitzem color a component ambient
    vec3 colRes = llumAmbient * matamb;

    // Afegim component difusa, si n'hi ha
    if (dot (L, NormSCO) > 0)
      colRes = colRes + colFocus * matdiff * dot (L, NormSCO);
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

vec3 Lambert2 (vec3 NormSCO, vec3 L) 
{
    // S'assumeix que els vectors que es reben com a paràmetres estan normalitzats

    // Inicialitzem color a component ambient
    vec3 colRes = llumAmbient * matamb1;

    // Afegim component difusa, si n'hi ha
    if (dot (L, NormSCO) > 0)
      colRes = colRes + colFocus * matdiff1 * dot (L, NormSCO);
    return (colRes);
}

vec3 Phong2 (vec3 NormSCO, vec3 L, vec4 vertSCO) 
{
    // Els vectors estan normalitzats

    // Inicialitzem color a Lambert
    vec3 colRes = Lambert2 (NormSCO, L);

    // Calculem R i V
    if (dot(NormSCO,L) < 0)
      return colRes;  // no hi ha component especular

    vec3 R = reflect(-L, NormSCO); // equival a: normalize (2.0*dot(NormSCO,L)*NormSCO - L);
    vec3 V = normalize(-vertSCO.xyz);

    if ((dot(R, V) < 0) || (matshin1 == 0))
      return colRes;  // no hi ha component especular
    
    // Afegim la component especular
    float shine = pow(max(0.0, dot(R, V)), matshin1);
    return (colRes + matspec1 * colFocus * shine); 
}

void main()
{	

    fcolor = matdiff;

    gl_Position = proj * view * TG * vec4 (vertex, 1.0);

    vec3 L, lnorm, NormSCO;
    vec4 vertexSCO;

    vertexSCO = view * TG * vec4(vertex,1);
    L = vec3(posFocus - vertexSCO);
    NormSCO = inverse(transpose(mat3(view * TG))) * normal;

    L = normalize(L);
    NormSCO = normalize(NormSCO);

    if(test == 1){
        fcolor = Phong2(NormSCO, L, vertexSCO);
    }
    else {
        fcolor = Phong(NormSCO, L, vertexSCO);
    }
    
    
}
