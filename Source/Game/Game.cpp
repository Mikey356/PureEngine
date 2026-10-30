#include "Game.h"
#include "Backend/Backend.h"
namespace Game
{
	Player g_player;
	float g_deltaTime = 0;
	float g_currentFrame = 0;
	float g_lastFrame = 0;

	void Init()
	{
		glm::vec3 position(0.0f, 0.0f, 3.0f);
		glm::vec3 rotation(0.0f, 0.0f, 0.0f);
		g_player.Init(position, rotation);
	}

	void Update()
	{
		g_currentFrame = static_cast<float>(Backend::GetGlfwTime());
		g_deltaTime = g_currentFrame - g_lastFrame;
		g_lastFrame = g_currentFrame;

		g_player.Update(g_deltaTime);
	}

	//// Idk if this has a purpose, if it does uncomment it
	//const float& GetDeltaTime()
	//{
	//	return g_deltaTime;
	//}

	Player& GetPlayer()		
	{
		return g_player;
	}

}