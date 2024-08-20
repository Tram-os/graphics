#ifndef TEXTURE_H
#define TEXUTRE_H

#include <string>


/**
 * Texture Class used for loading and creating textures
 */
class Texture
{
private:
	unsigned int m_RendererID; // the ID of the texture
	std::string m_Filepath; // filepath of the image
	unsigned char* m_Buffer; // contains the raw data of image
	int m_Width, m_Height, m_BPP; // the width, height, and bits per pixel of the image

public:
	/**
	 * Constructor that creates a texture object from a given path
	 * 
	 * @param[in] path const reference to the path of the texture file
	 * 
	 * @return a texture instance
	 */
	Texture(const std::string& path);

	/**
	 * Deconstructor
	 */
	~Texture();

	/**
	 * Binds the texture
	 * 
	 * @param[in] slot The texture slot to bind to, defaults to slot 0
	 */
	void Bind(unsigned int slot = 0) const;

	/**
	 * Unbinds the texture
	 */
	void Unbind();
	
	/**
	 * Gets the width of the texture object
	 * 
	 * @return m_Width The internal with member variable
	 */
	inline int GetWidth() const { return m_Width; }
	
	/**
	 * Gets the height of the texture object
	 *
	 * @return m_Height The internal with member variable
	 */
	inline int GetHeight() const { return m_Height; }


};

#endif // !TEXTURE_H
