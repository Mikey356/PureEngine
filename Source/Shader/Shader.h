#pragma once

#include <glad/glad.h>	
#include <glm/glm.hpp>
#include <string>
#include <unordered_map>

class Shader
{
public:
	void Load(const std::string& vertexPath, const std::string& fragmentPath);
	void Load(const std::string& vertexPath, const std::string& fragmentPath, const std::string& geomPath);
	void Use();
	void SetBool(const std::string& name, bool value);
	void SetInt(const std::string& name, int value);
	void SetFloat(const std::string& name, float value);
	void SetMat4(const std::string& name, glm::mat4 value);
	void SetVec4(const std::string& name, const glm::vec4& value);
	void SetVec3(const std::string& name, const glm::vec3& value);
	void SetVec2(const std::string& name, const glm::vec2& value);
private:
	int m_ID = -1;
	std::unordered_map<std::string, int> m_uniformsLocations;
};
class ComputeShader
{
public:
	void Load(const std::string& computePath);
	void Use() const;
	void SetBool(const std::string& name, bool value);
	void SetInt(const std::string& name, int value);
	void SetFloat(const std::string& name, float value);
	void SetVec2(const std::string& name, const glm::vec2& value);
	void SetVec2(const std::string& name, float x, float y);
	void SetVec3(const std::string& name, const glm::vec3& value);
	void SetVec3(const std::string& name, float x, float y, float z);
	void SetVec4(const std::string& name, const glm::vec4& value);
	void SetVec4(const std::string& name, float x, float y, float z, float w);
	void SetMat2(const std::string& name, const glm::mat2& mat);
	void SetMat3(const std::string& name, const glm::mat3& mat);
	void SetMat4(const std::string& name, const glm::mat4& mat);
private:
	void CheckCompileErrors(GLuint shader, std::string type);
	int m_ID = -1;
	std::unordered_map<std::string, int> m_uniformsLocations;
};
