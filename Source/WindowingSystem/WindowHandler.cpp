#include <iostream>
#include <glad/glad.h>
#include "WindowHandler.h"
#include "PureDefines.h"
#include "FunctionCallbacks/FunctionCallback.h"

WindowHandler::WindowHandler() 
{
	glfwInit();
	glfwWindowHint(PURE_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(PURE_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(PURE_OPENGL_PROFILE, PURE_OPENGL_CORE_PROFILE);
	glfwWindowHint(PURE_OPENGL_DEBUG_CONTEXT, true);
}

GLFWwindow* WindowHandler::GetWindow() 
{
	return m_window;
}
void WindowHandler::SetWindow(GLFWwindow* window)
{
	m_window = window;
}
const unsigned int& WindowHandler::GetWindowHeight() const
{
	return SCREEN_HEIGHT;
}
const unsigned int& WindowHandler::GetWindowWidth() const
{
	return SCREEN_WIDTH;
}
void WindowHandler::SetWindowHeight(unsigned int height)
{
	SCREEN_HEIGHT = height;
}
void WindowHandler::SetWindowWidth(unsigned int width)
{
	SCREEN_WIDTH = width;
}
GLFWwindow* WindowHandler::CreateWindow(const char* t, GLFWmonitor* monitor, GLFWwindow* share)
{
	m_window= glfwCreateWindow(WindowHandler::GetWindowWidth(), WindowHandler::GetWindowHeight(), t, monitor, share);
	if (m_window == NULL)
	{
		std::cout << "Failed to create GLFW window!" << std::endl;
		glfwTerminate();
	}
	
	glfwMakeContextCurrent(m_window);
	glfwSetFramebufferSizeCallback(m_window, FunctionCallback::frame_buffer_size_callback);
	glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	return m_window;
}
void WindowHandler::ProcessInput()
{
	if (glfwGetKey(WindowHandler::GetWindow(), GLFW_KEY_ESCAPE) == true)
		glfwSetWindowShouldClose(WindowHandler::GetWindow(), true);
}
WindowHandler::~WindowHandler()
{
	glfwDestroyWindow(WindowHandler::GetWindow());
}