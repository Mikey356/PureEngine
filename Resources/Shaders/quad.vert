#version 460 core
layout (location = 0) in vec3 attrib_pos;
layout (location = 1) in vec3 attrib_normal;
layout (location = 2) in vec2 attrib_uvs;
layout (location = 3) in vec3 attrib_tangent;

out vec3 v_Color;
uniform vec3 u_color;
uniform mat4 u_projection;
uniform mat4 u_view;

void main()
{
	gl_Position = u_projection * u_view * vec4(attrib_pos, 1.0f);
	v_Color = u_color;
}