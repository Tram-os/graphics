#ifndef INDEXBUFFER_H
#define INDEXBUFFER_H

/**
 * This class creates a index buffer object which has a private member variable of the renderer ID
 */
class IndexBuffer
{
private:
	unsigned int m_RendererID; // The id of the index buffer
	unsigned int m_Count; // The indice count in index buffer
public:
	/**
	 * Constructor for index buffer
	 * 
	 * @param[in] data const pointer to the data being loaded into the vertex buffer
	 * @param[in] size the size of the data being buffered
	 * 
	 * @return vertex buffer object
	 */
	IndexBuffer(const unsigned int* data, unsigned int count);

	/**
	 * Deconstructor for index buffer
	 */
	~IndexBuffer();

	/**
	 * Binds the index buffer
	 */
	void Bind() const;

	/**
	 * Unbinds the index buffer
	 */
	void Unbind() const;

	/**
	 * Returns the number of indices in the index buffer
	 */
	inline unsigned int GetCount() const { return m_Count; }
};

#endif