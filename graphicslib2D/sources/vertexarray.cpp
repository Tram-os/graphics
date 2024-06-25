#include "vertexarray.h"
#include "vertexbufferlayout.h"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &m_RendererID);
}
VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_RendererID);
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
	// First bind the vertex array
	Bind();

	// Bind the vertex buffer provided to the vertex array (This is how the Vertex array knows how much data
	// The data and size of data is already buffered in the vb 
	vb.Bind();

	// Get the vector of VertexBufferElemetns
	const std::vector<VertexBufferElement>& elements = layout.GetElements();
	unsigned int offset = 0;

	// Specify the layout for each element of the vector
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		const VertexBufferElement& element = elements[i];
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStide(), (const void*)offset);
		offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
	}
}

void VertexArray::Bind() const
{
	glBindVertexArray(m_RendererID);
}

void VertexArray::Unbind() const
{
	glBindVertexArray(0);
}
