#pragma once
#include <string>

struct Texture
{
	Texture() = default;

	void LoadTexture(const std::string& path, const std::string& directory);
	uint32_t GetHandle() const { return m_handle; }
	const std::string& GetTextureByName() const { return m_name; }
	const std::string& GetTextureByType() const { return m_type; }
	const std::string& GetTexturePath() const { return m_path; }

private:
	uint32_t m_handle;
	std::string m_name;
	std::string m_type;
	std::string m_path;
};