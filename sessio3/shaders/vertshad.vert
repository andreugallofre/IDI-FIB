#version 330 core

in vec3 vertex;
uniform float val;
in vec3 color;
out vec3 fcolor;

uniform mat4 TG;
uniform mat4 RG;
uniform mat4 SG;



void main()  {
	fcolor = color;
    gl_Position =  TG * SG * RG * vec4 (vertex, 1.0);
}
