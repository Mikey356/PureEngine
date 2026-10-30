#include "Renderer/Renderer.h"
#include "OpenGL/Essentials/Shader.h"
#include "Backend/Backend.h"
#include "Game/Game.h"
#include "Types/constants.h"
#include "Types/Model.h"
#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <unordered_map>

namespace Renderer
{
	
	RenderMode g_renderMode;
	
	std::unordered_map<std::string, Shader> g_shaders;
	std::unordered_map<std::string, Model> g_models;
	
	void CreateShader(const std::string& name, const std::string& vertPath, const std::string& fragPath);
	void CreateModel(const std::string& name, const std::string& path);
	void CreateModel(const std::string& name, const std::vector<Vertex>& vertices, const std::vector<uint32_t>& indices);
	Shader* GetShader(const std::string& name);
	Model* GetModel(const std::string& name);

	void Init()
	{
		glEnable(GL_DEPTH_TEST);
		std::vector<Vertex> vertices;
		
		vertices.emplace_back(Vertex( 0.5f,  0.5f, 0.0f));
		vertices.emplace_back(Vertex( 0.5f, -0.5f, 0.0f));
		vertices.emplace_back(Vertex(-0.5f, -0.5f, 0.0f));
		vertices.emplace_back(Vertex(-0.5f,  0.5f, 0.0f));
	
		std::vector<uint32_t> indices = { 0, 1, 3, 1, 2, 3 };

		CreateModel("Quad", vertices, indices);
		CreateModel("Mech", "Resources/Models/Mech.obj");
		CreateShader("QuadShader", "Resources/Shaders/quad.vert", "Resources/Shaders/quad.frag");
	}

	void RenderFrame()
	{
		Model* model = GetModel("Quad");
		/*Model* model2 = GetModel("Mech");*/
		Shader* quadShader = GetShader("QuadShader");
		if (!quadShader) return;
		if (!model) return;
		/*if (!model2) return;*/
		
		// Clear framebuffer
		glClearColor(0.4, 0.3, 2, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glm::mat4 projection = glm::perspective(glm::radians(PURE_FOV), (float)Backend::GetCurrentWindowWidth() / Backend::GetCurrentWindowHeight(), PURE_NEAR_PLANE, PURE_FAR_PLANE);
		glm::mat4 view = Game::GetPlayer().GetCamera().GetViewMatrix();
		quadShader->Activate();
		quadShader->SetMat4("u_view", view);
		quadShader->SetMat4("u_projection", projection);
		glm::vec3 vertexColor = PURE_COLOR_MAROON;
		quadShader->SetVec3("u_color", vertexColor);

		for (Mesh& mesh : model->m_meshes)
		{
			glBindVertexArray(mesh.m_vao);
			glDrawElements(GL_TRIANGLES, mesh.GetIndexCount(), GL_UNSIGNED_INT, 0);
			glDrawElements(GL_POINTS, mesh.GetIndexCount(), GL_UNSIGNED_INT, 0);
		}

		//for (Mesh& mesh : model2->m_meshes) 
		//{
		//	glBindVertexArray(mesh.m_vao);
		//	glDrawElements(GL_TRIANGLES, mesh.GetIndexCount(), GL_UNSIGNED_INT, 0);
		//}
		glPointSize(8.0f);

	}
	
	void HotLoadShaders()
	{
		for (auto& it : g_shaders) {
			it.second.HotLoad();
		}
	}
	void CreateShader(const std::string& name, const std::string& vertPath, const std::string& fragPath)
	{
		// Create shader and loads paths
		g_shaders[name] = Shader();
		g_shaders[name].Load(vertPath, fragPath);
	}

	void CreateModel(const std::string& name, const std::string& path)
	{
		// Create shader and loads paths
		g_models[name] = Model();
		g_models[name].Load(path);
	}

	void CreateModel(const std::string& name, const std::vector<Vertex>& vertices, const std::vector<uint32_t>& indices)
	{
		// Create shader and loads paths
		g_models[name] = Model();
		g_models[name].Load(vertices, indices);
	}

	Shader* GetShader(const std::string& name)
	{
		for (auto& it : g_shaders)
		{
			// if there's a matching shader name, return the shader
			if (it.first == name)
				return &it.second;
			// otherwise, return null pointer
			else
				return nullptr;
		}
	}
	Model* GetModel(const std::string& name)
	{
		for (auto& it : g_models)
		{
			// if there's a matching model name, return the model
			if (it.first == name) 
				return &it.second;
			
			// otherwise, return null pointer
			else {
				std::cout << "ERROR::INVALID MODEL OBJECT BRAH\n";
				return nullptr;
			}
		}
	}
	void ToggleWireFrame()
	{
		if (g_renderMode == RenderMode::SOLID) {
			g_renderMode = RenderMode::WIREFRAME;		}
		else {
			g_renderMode = RenderMode::SOLID;		}
		SetRenderMode(g_renderMode);
	}

	void SetRenderMode(RenderMode renderMode)
	{
		if (renderMode == RenderMode::SOLID)
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}
		else
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}
	}
	

	void Cleanup()
	{
		for (auto& it : g_shaders) it.second.Cleanup();
		for (auto& it : g_models) it.second.Cleanup();

	}
}