#pragma once
#include "common.h"
#include <vector>

struct Mesh
{
	void Create(const std::vector<Vertex>& vertices, const std::vector<uint32_t>& indices);
	void Upload();
	void Cleanup();
	
	size_t GetVertexCount() { return m_vertices.size(); }
	size_t GetIndexCount()  { return m_indices.size(); }


	uint32_t m_vao;
	uint32_t m_vbo;
	uint32_t m_ebo;

	std::vector<Vertex> m_vertices;
	std::vector<uint32_t> m_indices;
};