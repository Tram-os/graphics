#include "texture.h"
#include "glew.h"

#include "helpers/stb_image.h"

Texture::Texture(const std::string& path)
	: m_RendererID(0), m_Filepath(path), m_Buffer(nullptr), m_Width(0), m_Height(0), m_BPP(0)
{
	// Flip the texture when loaded in because opengl loads pictures upside down
	stbi_set_flip_vertically_on_load(1);
	m_Buffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 4); // use 4 channels for RGBA

	glGenTextures(1, &m_RendererID);
	glBindTexture(GL_TEXTURE_2D, m_RendererID);

	// Specify these four parameters... if you don't the texture will just not work and be rendered all black
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);

	if (m_Buffer) 
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_Buffer);
		glBindTexture(GL_TEXTURE_2D, 0);
		stbi_image_free(m_Buffer);
	}
	else 
	{
		printf("[ERROR] FAiled to load texturre");
		printf(stbi_failure_reason());
		__debugbreak();
	}
}

Texture::~Texture()
{
	glDeleteTextures(1, &m_RendererID);
}

void Texture::Bind(unsigned int slot) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, m_RendererID);
}

void Texture::Unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
