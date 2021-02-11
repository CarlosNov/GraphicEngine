#version 330 core

in vec3 inPos;	
in vec3 inColor;
in vec2 inTexCoord;
in vec3 inNormal;

uniform mat4 modelViewProj;
uniform mat4 modelView;
uniform mat4 normal;

out vec3 FragPos;
out vec2 TexCoords;
out vec3 Normal;

void main()
{
    TexCoords = inTexCoord;
    Normal = (normal * vec4(inNormal, 0.0)).xyz;
	FragPos = (modelView * vec4(inPos, 1.0)).xyz;
	
	gl_Position =  modelViewProj * vec4 (inPos,1.0);
}