#include "Windowing.h"

const unsigned int& Windowing::GetScreenHeight() const
{
	return m_ScreenHeight;
}

const unsigned int& Windowing::GetScreenWidth() const
{
	return m_ScreenWidth;
}

void Windowing::SetScreenHeight(unsigned int height)
{
	m_ScreenHeight = height;
}

void Windowing::SetScreenWidth(unsigned int width)
{
	m_ScreenWidth = width;
}

const GLFWwindow& Windowing::GetWindow() const
{
	return *m_window;
}

const GLFWwindow* Windowing::GetPointerToWindow() const
{
	return m_window;
}

auto& Windowing::WindowInit()  const
{
	 return glfwInit;
}

auto& Windowing::WindowTerminate() const
{
	return glfwTerminate;
}

void Windowing::CreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share)
{
	glfwCreateWindow(width, height, title, monitor, share);
}

void Windowing::WindowHint(int hint, int value)
{
	glfwWindowHint(hint, value);
}

auto& Windowing::WindowShouldClose() const
{
	return glfwWindowShouldClose;
}

void Windowing::SwapWindowBuffers(GLFWwindow* window)
{
	glfwSwapBuffers(window);
}

auto& Windowing::WindowPollEvents() const
{
	return glfwPollEvents;
}