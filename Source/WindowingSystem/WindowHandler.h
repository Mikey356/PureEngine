#pragma once
#include <glfw3.h>

class WindowHandler
{
private:
	GLFWwindow* m_window;
	unsigned int SCREEN_HEIGHT;
	unsigned int SCREEN_WIDTH;
public:
    GLFWwindow* GetWindow();
	void SetWindow(GLFWwindow* window);
	const unsigned int& GetWindowHeight() const;
	const unsigned int& GetWindowWidth() const;
	void SetWindowHeight(unsigned int height);
	void SetWindowWidth(unsigned int height);
	void ProcessInput();
	GLFWwindow* CreateWindow(const char* t, GLFWmonitor* monitor, GLFWwindow* share);
	WindowHandler();
	~WindowHandler();
};