#include <iostream>
#include "WindowingSystem/WindowHandler.h"
#include "Input/Input.h"
#include "GraphicsDebugger/Debug.h"

int main()
{
	
	WindowHandler windowHandler;
	windowHandler.SetWindowHeight(1080);
	windowHandler.SetWindowWidth(1920);
	GLFWwindow* window = windowHandler.CreateWindow("PureEngine", NULL, NULL);
	windowHandler.SetWindow(window);
	TextBasedDebugger::EnableDebugger();
	glTexParameteri(GL_FRAMEBUFFER, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	while (!glfwWindowShouldClose(window))
	{
		Input::ProcessInput(window);
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	
	glfwTerminate();
	return 0;
}