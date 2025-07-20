#include "Input.h"

namespace Input
{
	void ProcessInput(GLFWwindow* window)
	{
		if (glfwGetKey(window, PURE_KEY_ESCAPE) == PURE_KEY_PRESS) {
			glfwSetWindowShouldClose(window, true);
		}
	}
}