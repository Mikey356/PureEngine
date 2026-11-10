#version 460 core
layout (location = 0) in vec3 attrib_pos;
layout (location = 1) in vec3 attrib_normal;
layout (location = 2) in vec2 attrib_uvs;
layout (location = 3) in vec3 attrib_tangent;

out vec3 v_color;
out vec3 v_worldPos;
out vec3 v_normal;

uniform mat4 u_projection;
uniform mat4 u_view;
uniform mat4 u_model;
void main()
{
	vec4 worldPosition = u_model * vec4(attrib_pos,1.0f);
	v_worldPos = worldPosition.xyz;
	v_normal = attrib_normal;
	gl_Position = u_projection * u_view * u_model * worldPosition;
}