#include "Input.h"
#include "Backend/Backend.h"
#include <glfw3.h>

namespace Input
{
	bool g_keyDown[348];
	bool g_keyDownPreviousFrame[348];
	bool g_leftMouseDown = false;
	bool g_leftMouseDownPreviousFrame = false;
	bool g_rightMouseDownPreviousFrame = false;
	bool g_rightMouseDown = false;
	double g_mouseXPos = 0;
	double g_mouseYPos = 0;
	double g_mousePreviousXPos = 0;
	double g_mousePreviousYPos = 0;
	double g_mouseXPosOffset = 0;
	double g_mouseYPosOffset = 0;

	void Update()
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Backend::GetWindowPtr());
		if (!window)return;
		// loop through and query keys, set previous key frame 
		for (int i = 32; i < 348; ++i)
		{
			g_keyDownPreviousFrame[i] = g_keyDown[i];
			g_keyDown[i] = glfwGetKey(window, i) == GLFW_PRESS;
		}

		// query mouse buttons, set previous button frame 
		g_leftMouseDownPreviousFrame = g_leftMouseDown;
		g_leftMouseDown = (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS);
		
		g_rightMouseDownPreviousFrame = g_rightMouseDown;
		g_rightMouseDown = (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS);

		// Set cursor position coordinates
		g_mousePreviousXPos = g_mouseXPos;
		g_mousePreviousYPos = g_mouseYPos;
		glfwGetCursorPos(window, &g_mouseXPos, &g_mouseYPos);

		// compute how much the cursor moved in x and y directions
		g_mouseXPosOffset = g_mouseXPos - g_mousePreviousXPos;
		g_mouseYPosOffset = g_mousePreviousYPos - g_mouseYPos;
	}

	void SetMousePosition(int x, int y)
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Backend::GetWindowPtr());
		glfwSetCursorPos(window, (double)x, (double)y);
		g_mouseXPos = (double)x;
		g_mouseYPos = (double)y;
		g_mousePreviousXPos = (double)x;
		g_mousePreviousYPos = (double)y;
		// reset cursor position
		g_mouseXPosOffset = 0;
		g_mouseYPosOffset = 0;
	}

	bool KeyPressed(int keyCode)
	{
		// checks if this key hasn't been pressed the previous frame, if it's not return  true
		return  g_keyDown[keyCode] && !g_keyDownPreviousFrame[keyCode];
	}

	bool KeyDown(int keyCode)
	{
		return g_keyDown[keyCode];
	}

	bool LeftMousePressed()
	{
		return g_leftMouseDown && !g_leftMouseDownPreviousFrame;
	}

	bool LeftMouseDown()
	{
		return g_leftMouseDown;
	}

	bool RightMousePressed()
	{
		return g_rightMouseDown && !g_rightMouseDownPreviousFrame;
	}

	bool RightMouseDown()
	{
		return g_rightMouseDown;
	}

	int GetMouseXPos()
	{
		return (int)g_mouseXPos;
	}

	int GetMouseYPos()
	{
		return (int)g_mouseYPos;
	}

	int GetMouseXPosOffset() {
		return (int)g_mouseXPosOffset;
	}

	int GetMouseYPosOffset() {
		return (int)g_mouseYPosOffset;
	}
}