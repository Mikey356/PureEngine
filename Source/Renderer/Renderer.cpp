#include "Renderer.h"

Renderer::Renderer()
{
	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);
	glBindVertexArray(m_VAO);
	glBindBuffer(GL_VERTEX_ARRAY, m_VBO);
}


const unsigned int& Renderer::GetVBO() const
{
	return m_VBO;
}

const unsigned int& Renderer::GetVAO() const
{
	return m_VAO;
}

void Renderer::SetVBO(unsigned int vbo)
{
	m_VBO = vbo;
}


void Renderer::SetVBO(unsigned int vao)
{
	m_VAO = vao;
}
const unsigned int& Renderer::GetTexture1() const
{
	return m_texture1;
}
const unsigned int& Renderer::GetTexture2() const
{
	return m_texture2;
}
void Renderer::SetTextures(unsigned int texture1, unsigned int texture2)
{
	m_texture1 = texture1;
	m_texture2 = texture2;
}
void Renderer::ConfigureCubeData( std::vector<float>& vertex, std::vector<glm::vec3>& cube_positions)
{
	std::vector<float>	   vertices;
	std::vector<glm::vec3> positions;
	std::vector<glm::vec2> texCoords;
	std::vector<glm::vec3> cubePositions;
	positions.emplace_back(-0.5f, -0.5f, -0.5f);
	positions.emplace_back(0.5f, -0.5f, -0.5f);
	positions.emplace_back(0.5f, 0.5f, -0.5f);
	positions.emplace_back(0.5f, 0.5f, -0.5f);
	positions.emplace_back(-0.5f, 0.5f, -0.5f);
	positions.emplace_back(-0.5f, -0.5f, -0.5f);
	positions.emplace_back(-0.5f, -0.5f, -0.5f);
	positions.emplace_back(-0.5f, -0.5f, 0.5f);
	positions.emplace_back(0.5f, -0.5f, 0.5f);
	positions.emplace_back(0.5f, 0.5f, 0.5f);
	positions.emplace_back(0.5f, 0.5f, 0.5f);
	positions.emplace_back(-0.5f, 0.5f, 0.5f);
	positions.emplace_back(-0.5f, -0.5f, 0.5f);
	positions.emplace_back(-0.5f, 0.5f, 0.5f);
	positions.emplace_back(-0.5f, 0.5f, -0.5f);
	positions.emplace_back(-0.5f, -0.5f, -0.5f);
	positions.emplace_back(-0.5f, -0.5f, -0.5f);
	positions.emplace_back(-0.5f, -0.5f, 0.5f);
	positions.emplace_back(- 0.5f, 0.5f, 0.5f);
	positions.emplace_back(0.5f, 0.5f, 0.5f);
	positions.emplace_back(0.5f, 0.5f, -0.5f);
	positions.emplace_back(0.5f, -0.5f, -0.5f);
	positions.emplace_back(0.5f, -0.5f, -0.5f);
	positions.emplace_back(0.5f, -0.5f, 0.5f);
	positions.emplace_back(0.5f, 0.5f, 0.5f);
	positions.emplace_back(-0.5f, -0.5f, -0.5f);
	positions.emplace_back(0.5f, -0.5f, -0.5f);
	positions.emplace_back(0.5f, -0.5f, 0.5f);
	positions.emplace_back(0.5f, -0.5f, 0.5f);
	positions.emplace_back(-0.5f, -0.5f, 0.5f);
	positions.emplace_back(-0.5f, -0.5f, -0.5f);
	positions.emplace_back(-0.5f, 0.5f, -0.5f);
	positions.emplace_back(0.5f, 0.5f, -0.5f);
	positions.emplace_back(0.5f, 0.5f, 0.5f);
	positions.emplace_back(0.5f, 0.5f, 0.5f);
	positions.emplace_back(-0.5f, 0.5f, 0.5f);
	positions.emplace_back(-0.5f, 0.5f, -0.5f);
	texCoords.emplace_back(0.0f, 0.0f);
	texCoords.emplace_back(1.0f, 0.0f);
	texCoords.emplace_back(1.0f, 1.0f);
	texCoords.emplace_back(1.0f, 1.0f);
	texCoords.emplace_back(0.0f, 1.0f);
	texCoords.emplace_back(0.0f, 0.0f);
	texCoords.emplace_back(0.0f, 0.0f);
	texCoords.emplace_back(1.0f, 0.0f);
	texCoords.emplace_back(1.0f, 1.0f);
	texCoords.emplace_back(1.0f, 1.0f);
	texCoords.emplace_back(0.0f, 1.0f);
	texCoords.emplace_back(0.0f, 0.0f);
	texCoords.emplace_back(1.0f, 0.0f);
	texCoords.emplace_back(1.0f, 1.0f);
	texCoords.emplace_back(0.0f, 1.0f);
	texCoords.emplace_back(0.0f, 1.0f);
	texCoords.emplace_back(0.0f, 0.0f);
	texCoords.emplace_back(1.0f, 0.0f);
	texCoords.emplace_back(1.0f, 0.0f);
	texCoords.emplace_back(1.0f, 1.0f);
	texCoords.emplace_back(0.0f, 1.0f);
	texCoords.emplace_back(0.0f, 1.0f);
	texCoords.emplace_back(0.0f, 0.0f);
	texCoords.emplace_back(1.0f, 0.0f);
	texCoords.emplace_back(0.0f, 1.0f);
	texCoords.emplace_back(1.0f, 1.0f);
	texCoords.emplace_back(1.0f, 0.0f);
	texCoords.emplace_back(1.0f, 0.0f);
	texCoords.emplace_back(0.0f, 0.0f);
	texCoords.emplace_back(0.0f, 1.0f);
	texCoords.emplace_back(0.0f, 1.0f); 
	texCoords.emplace_back(0.0f, 1.0f);
	texCoords.emplace_back(1.0f, 1.0f);
	texCoords.emplace_back(1.0f, 0.0f);
	texCoords.emplace_back(1.0f, 0.0f);
	texCoords.emplace_back(0.0f, 0.0f);
	texCoords.emplace_back(0.0f, 1.0f);
	vertices.reserve(positions.size() + texCoords.size());
	vertices.insert(vertices.end(), positions.begin(), positions.begin());
	vertices.insert(vertices.end(), texCoords.begin(), texCoords.begin());
	cubePositions.emplace_back( 0.0f, 0.0f, 0.0f);
	cubePositions.emplace_back( 2.0f, 5.0f,-15.0f);
	cubePositions.emplace_back(-1.5f,-2.2f,-2.5f);
	cubePositions.emplace_back(-3.8f,-2.0f,-12.3f);
	cubePositions.emplace_back( 2.4f,-0.4f,-3.5f);
	cubePositions.emplace_back(-1.7f, 3.0f,-7.5f);
	cubePositions.emplace_back( 1.3f,-2.0f,-2.5f);
	cubePositions.emplace_back( 1.5f, 2.0f,-2.5f);
	cubePositions.emplace_back( 1.5f, 0.2f,-1.5f);
	cubePositions.emplace_back(-1.3f, 1.0f, -1.5f);
	vertex = vertices;
	cube_positions = cubePositions;
}			


unsigned int Renderer::LoadTexture(const char* path)
{
	unsigned int textureID;
	glGenTextures(1, &textureID);

	int width, height, numComponents;
	unsigned char* data = stbi_load(path, &width, &height, &numComponents, 0);
	if (data)
	{
		GLenum format;
		if (numComponents == 1)
			format = GL_RED;
		else if (numComponents == 3)
			format = GL_RGB;
		else if (numComponents == 4)
			format = GL_RGBA;

		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_image_free(data);
	}
	else
	{
		std::cout << "Texture failed to load at path: " << path << std::endl;
		stbi_image_free(data);
	}
	return textureID;
}

void Renderer::RenderCubes()
{
	std::vector<float> vertices;
	std::vector<glm::vec3> cubePositionz;
	ConfigureCubeData(vertices, cubePositionz);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	Shader testShader;
	testShader.Load("GL_Test.vert", "GL_Test.frag");
	unsigned int texture1 = LoadTexture("../Resources/Textures/container.jpg");
	unsigned int texture2 = LoadTexture("../Resources/Textures/awesomeface.png");
	SetTextures(texture1, texture2);
	testShader.SetInt("texture1", 0);
	testShader.SetInt("texture2", 1);
}