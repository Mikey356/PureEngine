#pragma once 
#include "keycodes.h"
namespace Input
{
	void Update();
	void SetMousePosition(int x, int y);
	bool KeyPressed(int keyCode);
	bool KeyDown(int keyCode);
	bool LeftMousePressed();
	bool LeftMouseDown();
	bool RightMousePressed();
	bool RightMouseDown();
	int GetMouseXPos();
	int GetMouseYPos();
	int GetMouseXPosOffset();
	int GetMouseYPosOffset();

}