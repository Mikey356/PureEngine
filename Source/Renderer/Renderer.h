#pragma once

enum struct RenderMode
{
	SOLID,
	WIREFRAME
};
namespace Renderer
{
	void Init();
	void RenderFrame();
	void ToggleWireFrame();
	void SetRenderMode(RenderMode renderMode);
	void HotLoadShaders();
	void Cleanup();
}