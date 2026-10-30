#version 460 core

layout (location = 0) in vec3 attribPos;
layout (location = 1) in vec2 attribUVs;

out vec2 v_UVs;
uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

void main()
{
	gl_Position = u_projection * u_view * u_model * vec4(attribPos, 1.0);	
	v_UVs = attribUVs;
}