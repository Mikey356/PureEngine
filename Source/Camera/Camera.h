#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Types/PureEnums.h>

class Camera
{
private:
	const float m_YAW;
	const float m_PITCH;
	float		m_SPEED;
	const float m_SENSETIVITY;
	const float m_ZOOM;
	void UpdateCameraVectors();
	void ConfigureCameraVectors();
public:
	// Camera Attributes
	glm::vec3 Position;
	glm::vec3 Front;
	glm::vec3 Up;
	glm::vec3 Right;
	glm::vec3 WorldUp;
	// euler angles
	float Yaw;
	float Pitch;
	// Camera Options
	float MovementSpeed;
	float MouseSensitivity;
	float Zoom;

	// constructor with vectors
	Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch);
};