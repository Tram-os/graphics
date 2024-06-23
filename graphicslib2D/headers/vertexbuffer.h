#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

/**
 * This class creates a vertex buffer object which has a private member variable of the renderer ID
 */
class VertexBuffer
{
private:
	unsigned int m_RendererID; // The idea of the vertex buffer
public:
	/**
	 * Constructor for vertex buffer
	 * 
	 * @param[in] data const pointer to the data being loaded into the vertex buffer
	 * @param[in] size the size of the data being buffered
	 * 
	 * @return vertex buffer object
	 */
	VertexBuffer(const void* data, unsigned int size);

	/**
	 * Deconstructor for vertex buffer
	 */
	~VertexBuffer();

	/**
	 * Binds the vertex buffer
	 */
	void Bind();

	/**
	 * Unbinds the vertex buffer
	 */
	void Unbind();
};

#endif