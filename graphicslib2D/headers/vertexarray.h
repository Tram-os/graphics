#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include "vertexbuffer.h"
#include "vertexbufferlayout.h"

class VertexArray
{
private:
	unsigned int m_RendererID;

public:
	/**
	 * Constructor, creates a Vertex Array object and sets the m_RendererID
	 * 
	 * @return VertexArray class instance
	 */
	VertexArray();

	/**
	 * Deconstructor
	 */
	~VertexArray();

	/**
	 * Adds the buffer to the Vertex Array object along with the defined layout.
	 * 
	 * @param[in] vb const reference to the vertex buffer that will be added
	 * @param[in] layout const reference to the vertex buffer layout
	 * 
	 * @return none
	 */
	void AddBuffer(const VertexBuffer & vb, const VertexBufferLayout & layout);

	/**
	 * Binds the vertex array
	 * 
	 * @return none
	 */
	void Bind() const;

	/**
	 * Unbinds the vertex array
	 *
	 * @return none
	 */
	void Unbind() const;
};

#endif