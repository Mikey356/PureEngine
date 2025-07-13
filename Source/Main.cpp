#include <iostream>
#include <glad/glad.h>
#include <glfw3.h>
#include "GraphicsDebugger/Debug.h"
#include "FunctionCallbacks/FunctionCallback.h"
const unsigned int SCR_HEIGHT = 1080;
const unsigned int SCR_WIDTH = 1920;
int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);
	
	GLFWwindow* g_window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "GraphicsDebugger", nullptr, nullptr);
	
	if (g_window == NULL)
	{
		std::cout << "Failed to create GLFW window!" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(g_window);
	glfwSetFramebufferSizeCallback(g_window, FunctionCallback::frame_buffer_size_callback);
	
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	
	int flags;  glGetIntegerv(GL_CONTEXT_FLAGS, &flags);
	
	auto debugOutput = TextBasedDebugger::glDebugOutput;
	if (flags & GL_CONTEXT_FLAG_DEBUG_BIT)
	{
		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS); // makes sure errors are displayed synchronously
		glDebugMessageCallback(debugOutput, nullptr);
		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
	}
	glDebugMessageControl(GL_DEBUG_SOURCE_API, GL_DEBUG_TYPE_ERROR, GL_DEBUG_SEVERITY_HIGH, 0, nullptr, GL_TRUE);
	glTexParameteri(GL_FRAMEBUFFER, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	while (!glfwWindowShouldClose(g_window)) {
		glfwPollEvents();
		glfwSwapBuffers(g_window);
	}

	

	glfwTerminate();
	return 0;
}

