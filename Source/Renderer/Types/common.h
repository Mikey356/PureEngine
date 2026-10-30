#pragma once
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/quaternion.hpp"



struct Vertex
{
	Vertex() = default;
	// for primitive
	Vertex(float x, float y, float z) {
		m_position = glm::vec3(x, y, z);
	}
	glm::vec3 m_position;
	glm::vec3 m_normal;
	glm::vec2 m_uvs;
	glm::vec3 m_tangent;
};

struct Transform
{
	glm::vec3 position = glm::vec3(0.0f);
	glm::vec3 rotation = glm::vec3(0.0f);
	glm::vec3 scale = glm::vec3(0.0f);


	glm::mat4 ToMat4()
	{
		glm::mat4 mat = glm::translate(glm::mat4(1.0f), position);
		mat *= glm::mat4_cast(glm::quat(rotation));
		mat = glm::scale(mat, scale);
		return mat;
	}
};