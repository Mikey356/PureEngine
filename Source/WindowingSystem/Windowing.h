#include "glfw3.h"

class Windowing
{
private:
	unsigned int m_ScreenHeight;
	unsigned int m_ScreenWidth;
	GLFWwindow* m_window;

public:
	const unsigned int& GetScreenHeight() const;
	const unsigned int& GetScreenWidth() const;
	void SetScreenHeight(unsigned int height);
	void SetScreenWidth(unsigned int width);
	const GLFWwindow& GetWindow() const;
	const GLFWwindow* GetPointerToWindow() const;
	auto& WindowInit() const;
	auto& WindowTerminate() const;
	void CreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
	void MakeCurrentContext(GLFWwindow* window);
	void WindowHint(int hint, int value);
	auto& WindowShouldClose() const;
	void SwapWindowBuffers(GLFWwindow* window);
	auto& WindowPollEvents() const;
};