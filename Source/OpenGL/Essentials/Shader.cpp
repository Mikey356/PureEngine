#include "Shader.h"
#include <iostream>
#include <glad/glad.h>

/*Helper functions*/

// gets the vertex & fragment shader source code, and outputs it as an std::string
bool ParseShaderFileSource(const std::string& filePath,  std::string& outputSource);
bool CheckShaderCompilation(unsigned int shader, const std::string& shaderType);

void Shader::Load(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
{
	std::string vertSource;
	std::string fragSource;
	
	// If unable to read file, exit function
	if (!ParseShaderFileSource(vertexShaderPath, vertSource)) return;
	if (!ParseShaderFileSource(fragmentShaderPath, fragSource)) return;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	const std::string vertSrcCode = vertSource;
	const char* vertSrc = vertSrcCode.c_str();

	const std::string fragSrcCode = fragSource;
	const char* fragSrc = fragSrcCode.c_str();

	unsigned int gl_vert, gl_frag;

	gl_vert = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(gl_vert, 1, &vertSrc, nullptr);
	glCompileShader(gl_vert);
	CheckShaderCompilation(gl_vert, "VERTEX_SHADER");

	gl_frag = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(gl_frag, 1, &fragSrc, nullptr);
	glCompileShader(gl_frag);
	CheckShaderCompilation(gl_frag, "FRAGMENT_SHADER");

	m_handle = glCreateProgram();
	glAttachShader(m_handle, gl_vert);
	glAttachShader(m_handle, gl_frag);
	glLinkProgram(m_handle);
	CheckShaderCompilation(m_handle, "PROGRAM_SHADER");

	glDeleteShader(gl_vert);
	glDeleteShader(gl_frag);
	
	// store paths
	m_vertPath = vertexShaderPath;
	m_fragPath = fragmentShaderPath;
}
void Shader::HotLoad()
{
	std::string vertSource;
	std::string fragSource;

	// If unable to read file, exit function
	if (!ParseShaderFileSource(m_vertPath, vertSource)) return;
	if (!ParseShaderFileSource(m_fragPath, fragSource)) return;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	const std::string vertSrcCode = vertSource;
	const char* vertSrc = vertSrcCode.c_str();

	const std::string fragSrcCode = fragSource;
	const char* fragSrc = fragSrcCode.c_str();

	unsigned int gl_vert, gl_frag;

	gl_vert = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(gl_vert, 1, &vertSrc, nullptr);
	glCompileShader(gl_vert);
	CheckShaderCompilation(gl_vert, "VERTEX_SHADER");

	gl_frag = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(gl_frag, 1, &fragSrc, nullptr);
	glCompileShader(gl_frag);
	CheckShaderCompilation(gl_frag, "FRAGMENT_SHADER");

	uint32_t tempHandle = glCreateProgram();
	glAttachShader(tempHandle, gl_vert);
	glAttachShader(tempHandle, gl_frag);

	glLinkProgram(tempHandle);

	// Only update the handle if the hotload was successful
	if (CheckShaderCompilation(tempHandle, "PROGRAM") == true) m_handle = tempHandle;

	glDeleteShader(gl_vert);
	glDeleteShader(gl_frag);
}

void Shader::Activate() const {
	glUseProgram(m_handle);
}
const uint32_t Shader::GetHandle() const {
	return m_handle;
}
void Shader::Cleanup() {
	glDeleteProgram(m_handle);
}
void Shader::SetBool(const std::string& name, bool value) const {
	glUniform1i(glGetUniformLocation(m_handle, name.c_str()), (int)value);
}

void Shader::SetInt(const std::string& name, int value) const {
	glUniform1i(glGetUniformLocation(m_handle, name.c_str()), value);
}

void Shader::SetFloat(const std::string& name, float value) const {
	glUniform1f(glGetUniformLocation(m_handle, name.c_str()), value);
}

void Shader::SetVec2(const std::string& name, const glm::vec2& vec) const {
	glUniform2fv(glGetUniformLocation(m_handle, name.c_str()), 1, &vec[0]);
}
void Shader::SetVec2(const std::string& name, float x, float y) const {
	glUniform2f(glGetUniformLocation(m_handle, name.c_str()), x, y);
}

void Shader::SetVec3(const std::string& name, const glm::vec3& vec) const {
	glUniform3fv(glGetUniformLocation(m_handle, name.c_str()), 1, &vec[0]);
}
void Shader::SetVec3(const std::string& name, float x, float y, float z) const {
	glUniform3f(glGetUniformLocation(m_handle, name.c_str()), x, y, z);
}

void Shader::SetVec4(const std::string& name, const glm::vec4& vec) const {
	glUniform4fv(glGetUniformLocation(m_handle, name.c_str()), 1, &vec[0]);
}

void Shader::SetVec4(const std::string& name, float x, float y, float z, float w) const {
	glUniform4f(glGetUniformLocation(m_handle, name.c_str()), x, y, z, w);
}

void Shader::SetMat2(const std::string& name, const glm::mat2& mat) const
{
	glUniformMatrix2fv(glGetUniformLocation(m_handle, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::SetMat3(const std::string& name, const glm::mat3& mat) const
{
	glUniformMatrix3fv(glGetUniformLocation(m_handle, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::SetMat4(const std::string& name, const glm::mat4& mat) const
{
	glUniformMatrix4fv(glGetUniformLocation(m_handle, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

bool ParseShaderFileSource(const std::string& filePath, std::string& outputSource)
{

	std::ifstream file;

	file.open(filePath);
	if (!file.is_open())
	{
		std::cerr << "Failed to open " << filePath << std::endl;
		return false;
	}

	std::stringstream stringStream;
	stringStream << file.rdbuf();
	
	// also frees file buffer
	file.close();

	outputSource = stringStream.str();
	return true;
}

bool CheckShaderCompilation(unsigned int shader, const std::string& shaderType)
{
	GLint success;
	GLchar infoLog[1024];
	if (shaderType != "SHADER_PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << shaderType << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
			return false;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_LINKING_ERROR of type: " << shaderType << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
			return false;
		}
	}

	return true;
}