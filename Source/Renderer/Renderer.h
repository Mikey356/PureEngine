#include <glad/glad.h>
#include "WindowingSystem/WindowHandler.h"
#include "Types/PureDefines.h"
#include "Shader/Shader.h"
#include <glm/glm.hpp>
#include <stb_image.h>
#include <vector>
#include <iostream>

class Renderer
{
private:
	unsigned int m_VBO;
	unsigned int m_VAO;
	unsigned int m_texture1;
	unsigned int m_texture2;
	unsigned int LoadTexture(const char* path);
	void Update();
	void RenderScreen();
	void ConfigureCubeData(std::vector<float>& vertex, std::vector<glm::vec3>& cube_positions);
	void RenderCubes();
public:
	const unsigned int& GetVBO() const;
	const unsigned int& GetVAO() const;
	const unsigned int& GetTexture1() const;
	const unsigned int& GetTexture2() const;
	void SetTextures(unsigned int texture1, unsigned int texture2);
	void SetVBO(unsigned int vbo);
	void SetVAO(unsigned int vao);
	Renderer();
	~Renderer();
};