#ifndef VERTEXBUFFERLAYOUT_H
#define VERTEXBUFFERLAYOUT_H

#include <vector>
#include <glew.h>

/**
 * Struct contains the type, count and normalized vlaues for use in glVertexAttribPointer
 */
struct VertexBufferElement
{
	unsigned int type;
	unsigned int count;
	unsigned char normalized;

	/**
	 * returns the size of provided gl type
	 */
	static unsigned int GetSizeOfType(unsigned int type)
	{
		switch (type)
		{
			case GL_FLOAT:			return 4;
			case GL_UNSIGNED_INT:	return 4;
			case GL_UNSIGNED_BYTE:	return 1;
		}
		printf("[ERROR] Unknown Type");
		return 0;
	}
};

/**
 * Defines the layout of the vertex buffer (which is defined by the vertices the user is adding). 
 */
class VertexBufferLayout
{
private:
	std::vector<VertexBufferElement> m_Elements;
	unsigned int m_Stride;
public:
	VertexBufferLayout()
		: m_Stride(0) {}

	/**
	 * Define the number of elements each vertex of the buffer, along with the type of element.
	 * For example, if each vertice being added has an x, y, and z and are all floats, use Push<float>(3)
	 * 
	 * @param[in] The number of elements per vertice in the layout.
	 * 
	 */
	template<typename T>
	void Push(unsigned int count)
	{
		static_assert(false, "Pushing for this type has not been implemented.");
	}

	template<>
	void Push<float>(unsigned int count)
	{
		m_Elements.push_back({GL_FLOAT, count, GL_FALSE });
		m_Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
	}

	template<>
	void Push<unsigned int>(unsigned int count)
	{
		m_Elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
		m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
	}

	template<>
	void Push<unsigned char>(unsigned int count)
	{
		m_Elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
		m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
	}

	// Returns m_Elements
	inline const std::vector<VertexBufferElement> GetElements() const { return m_Elements; }

	// Returns m_Stride
	inline unsigned int GetStide() const { return m_Stride; }

};

#endif