#include "FunctionCallback.h"

namespace FunctionCallback
{

	void frame_buffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
}