#pragma once
#include "Mesh.h"
#include <string>
struct Model
{
	void Load(const std::string& path);
	void Load(const std::vector<Vertex>& vertices, const std::vector<uint32_t>& indices);
	void Cleanup();

	std::vector<Mesh> m_meshes;
};