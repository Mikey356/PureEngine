#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>
#include "Backend.h"
#include "Input/Input.h"

// Always select the dedicated GPU
extern "C"
{
	__declspec(dllexport) unsigned __int32 AmdPowerXpressRequestHighPerformance = 0x1;
	__declspec(dllexport) unsigned __int32 NvOptimusEnablement = 0x1;
}

namespace Backend
{
	void FramebufferSizeCallback(GLFWwindow* window, int width, int height);

	GLFWwindow* g_window = nullptr;
	GLFWmonitor* g_monitor = nullptr;
	const GLFWvidmode* g_vidMode = nullptr;
	int32_t g_currentWindowWidth = 0; 
	int32_t g_currentWindowHeight = 0;
	int32_t g_fullScreenWidth = 0;
	int32_t g_fullScreenHeight = 0;
	int32_t g_windowedWidth = 0;
	int32_t g_windowedHeight = 0;
	WindowMode g_windowMode;

	bool Init(const std::string& title, int32_t initialWidth, int32_t initialHeight)
	{
		glfwInit();

		g_monitor = glfwGetPrimaryMonitor();
		// Get full screen mode
		g_vidMode = glfwGetVideoMode(g_monitor);

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
		glfwWindowHint(GLFW_RED_BITS, g_vidMode->redBits);
		glfwWindowHint(GLFW_GREEN_BITS, g_vidMode->greenBits);
		glfwWindowHint(GLFW_BLUE_BITS, g_vidMode->blueBits);
		glfwWindowHint(GLFW_REFRESH_RATE, g_vidMode->refreshRate);

		g_window = glfwCreateWindow(initialWidth, initialHeight, title.c_str(), NULL, NULL);
		if (g_window == NULL)
		{
			std::cout << "Failed to create window" << std::endl;
			return false;
		}
		glfwMakeContextCurrent(g_window);
		glfwSetFramebufferSizeCallback(g_window, FramebufferSizeCallback);



		glfwSetInputMode(g_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		// set full screen width and height equal to the video mode's full screen
		g_fullScreenWidth = g_vidMode->width;
		g_fullScreenHeight = g_vidMode->height;
		

		g_windowedWidth = initialWidth;
		g_windowedHeight = initialHeight;
		
		// initial window mode is windowed
		SetWindowMode(WindowMode::WINDOWED);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			return false;
		}

		// print specs
		GLint major, minor;
		glGetIntegerv(GL_MAJOR_VERSION, &major);
		glGetIntegerv(GL_MINOR_VERSION, &minor);
		const GLubyte* vendor = glGetString(GL_VENDOR);
		const GLubyte* renderer = glGetString(GL_RENDERER);
		std::cout << "\nVendor: " << vendor << "\n";
		std::cout << "\nGPU: " << renderer << "\n";
		std::cout << "\nGL version: " << major << "." << minor << "\n";

		return true;
	}

	float GetGlfwTime() {
		return glfwGetTime();
	}

	void Cleanup() {
		glfwTerminate();
	}
	void BeginFrame(){
		Input::Update();
	}
	void EndFrame()
	{
		glfwPollEvents();
		glfwSwapBuffers(g_window);
	}
	void ToggleFullScreen()
	{
		if (g_windowMode == WindowMode::FULL_SCREEN) {
			g_windowMode = WindowMode::WINDOWED;
		}
		else
			g_windowMode = WindowMode::FULL_SCREEN;

		SetWindowMode(g_windowMode);
	}

	void SetWindowMode(WindowMode windowMode)
	{
		if (windowMode == WindowMode::FULL_SCREEN)
		{
			g_currentWindowWidth = g_fullScreenWidth;
			g_currentWindowHeight = g_fullScreenHeight;
		}
		else
		{
			g_currentWindowWidth = g_windowedWidth;
			g_currentWindowHeight = g_windowedHeight;
		}

		glfwSetWindowMonitor(g_window, nullptr, 0, 0, g_currentWindowWidth, g_currentWindowHeight, g_vidMode->refreshRate);
	}

	bool WindowShouldClose(){
		return glfwWindowShouldClose(g_window);
	}

	void ForceCloseWindow() {
		return glfwSetWindowShouldClose(g_window, true);
	}

	

	void SwapBuffers() {
		glfwPollEvents();
		glfwSwapBuffers(g_window);
	}

	void* GetWindowPtr() {
		return g_window;
	}

	int32_t GetCurrentWindowWidth() {
		return g_currentWindowWidth;
	}
	int32_t GetCurrentWindowHeight() {
		return g_currentWindowHeight;
	}
	int32_t GetFullScreenWidth() {
		return g_fullScreenWidth;
	}

	int32_t GetFullScreenHeight() {
		return g_fullScreenHeight;
	}

	void FramebufferSizeCallback(GLFWwindow* window, int width, int height)
	{
		g_currentWindowHeight = height;
		g_currentWindowWidth = width;

		glViewport(0, 0, g_currentWindowWidth, g_currentWindowHeight);
	}
}
