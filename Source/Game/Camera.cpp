#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
void Camera::Update()
{

	// to transform to view space
	glm::mat4 transMat = glm::translate(glm::mat4(1.0f), m_position);

	transMat *= glm::mat4_cast(glm::quat(m_rotation));
	m_inverseViewMatrix = transMat;
	m_viewMatrix = glm::inverse(m_inverseViewMatrix);

	// Create the view space unit axes
	m_forward = -glm::vec3(m_inverseViewMatrix[2]);
	m_up = glm::vec3(m_inverseViewMatrix[1]);
	m_right = glm::vec3(m_inverseViewMatrix[0]);
}

void Camera::SetPosition(const glm::vec3& position) { 
	m_position = position; 
}

void Camera::SetRotation(const glm::vec3& rotation) { 
	m_rotation = rotation; 
}