#pragma once
#include <string>

enum struct WindowMode
{
	WINDOWED,
	FULL_SCREEN
};

namespace Backend
{
	bool Init(const std::string& title, int32_t initialWidth, int32_t initialHeight);
	void Cleanup();
	void BeginFrame();
	void EndFrame();

	void ForceCloseWindow();
	void ToggleFullScreen();
	void SetWindowMode(WindowMode windowMode);


	bool WindowShouldClose();
	float GetGlfwTime();
	void* GetWindowPtr();
	int32_t GetCurrentWindowWidth();
	int32_t GetCurrentWindowHeight();
	int32_t GetFullScreenWidth();
	int32_t GetFullScreenHeight();

};