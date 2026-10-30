#include "Backend/Backend.h"
#include "Renderer/Renderer.h"
#include "Input/Input.h"
#include "Game/Game.h"
#include <iostream>

void HotKeys();

int main()
{
	Backend::Init("Hog", 1280, 720);
	Renderer::Init();
	Game::Init();
	while (!Backend::WindowShouldClose())
	{
		HotKeys();
		Renderer::RenderFrame();		
		Backend::BeginFrame();
		Game::Update();
		Backend::EndFrame();
		
	}
	Renderer::Cleanup();
	Backend::Cleanup();
	return 0; 
}

void HotKeys()
{
	if (Input::KeyPressed(PURE_KEY_ESCAPE)) Backend::ForceCloseWindow();
	
	if (Input::KeyPressed(PURE_KEY_X)) Renderer::ToggleWireFrame();

	if (Input::KeyPressed(PURE_KEY_H)) 
	{
		std::cout << "Hot load shaders\n";
		Renderer::HotLoadShaders();
	}

	if(Input::KeyPressed(PURE_KEY_F))	Backend::ToggleFullScreen();
}