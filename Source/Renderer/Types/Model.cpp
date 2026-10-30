#include "Model.h"
#define TINYOBJLOADER_DISABLE_FAST_FLOAT
#define TINYOBJLOADER_IMPLEMENTATION
#include "tinyobj_loader.h"
#include <iostream>

void Model::Load(const std::string& path)
{
    
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;

    std::string warn;
     std::string err;

    bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, path.c_str());

  /*  if (!warn.empty()) std::cout << warn << '\n';
    if (!err.empty())  std::cerr << err << '\n';
    if (!ret)          exit(1);*/

    // Loop over meshes in the model
    for (tinyobj::shape_t& shape : shapes) 
    {
        std::vector<Vertex> vertices;
        std::vector<uint32_t> indices;

        vertices.reserve(99999);
        indices.reserve(99999);

        // Loop over faces
        size_t index_offset = 0;

        // Loop over the triangles in the model mesh
        for (size_t f = 0; f < shape.mesh.num_face_vertices.size(); f++) 
        {
            size_t vertCount = size_t(shape.mesh.num_face_vertices[f]);

            // Loop over vertices in the face(triangle)
            for (size_t v = 0; v < vertCount; v++) 
            {
                // Access to tinyobj vertex
                tinyobj::index_t idx = shape.mesh.indices[index_offset + v];

                // Create My Indices
                indices.emplace_back(indices.size());

                // Create My Vertices
                Vertex& vertex = vertices.emplace_back();

                // Positions
                vertex.m_position.x = attrib.vertices[3 * size_t(idx.vertex_index) + 0];
                vertex.m_position.y = attrib.vertices[3 * size_t(idx.vertex_index) + 1];
                vertex.m_position.z = attrib.vertices[3 * size_t(idx.vertex_index) + 2];

                // Normals
                if (idx.normal_index >= 0)
                {
                   vertex.m_normal.x = attrib.normals[3 * size_t(idx.normal_index) + 0];
                   vertex.m_normal.y = attrib.normals[3 * size_t(idx.normal_index) + 1];
                   vertex.m_normal.z = attrib.normals[3 * size_t(idx.normal_index) + 2];
                }

                // UVs
                if (idx.texcoord_index >= 0) 
                {
                    vertex.m_uvs.x = attrib.texcoords[2 * size_t(idx.texcoord_index) + 0];
                    vertex.m_uvs.y = attrib.texcoords[2 * size_t(idx.texcoord_index) + 1];
                }
            }
           
            index_offset += vertCount;
           
        }
        
        std::cout << "-vertices: " << vertices.size() << std::endl;
        std::cout << "-indices: " << indices.size() << std::endl;
             
        Mesh& mesh = m_meshes.emplace_back();
        mesh.Create(vertices, indices);
        mesh.Upload();
    }
}

void Model::Load(const std::vector<Vertex>& vertices, const std::vector<uint32_t>& indices)
{
	m_meshes.clear();
	Mesh& mesh = m_meshes.emplace_back();
	mesh.Create(vertices, indices);
	mesh.Upload();
}

void Model::Cleanup()
{
	for (auto& mesh : m_meshes) mesh.Cleanup();
}