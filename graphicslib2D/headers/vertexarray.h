#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include "vertexbuffer.h"
#include "vertexbufferlayout.h"

class VertexArray
{
private:
	unsigned int m_RendererID;

public:
	VertexArray();
	~VertexArray();

	void AddBuffer(const VertexBuffer & vb, const VertexBufferLayout & layout);
	void Bind() const;
	void Unbind() const;
};

#endif