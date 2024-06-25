#ifndef RENDERER_H
#define RENDERER_H

#include "indexbuffer.h"
#include "shader.h"
#include "vertexarray.h"

/**
 * Defines Renderer Class that handles all of the draw calls
 * 
 */
class Renderer
{
private:

public:
	Renderer();

	/**
	 * Handles the actual drawing
	 * 
	 * @param[in] va const refernce to the vertex array instance being uesed
	 * @param[in] ib const reference to the index buffer instance being used
	 * @param[in] shader const reference to the shader insance being used
	 */
	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;

	/**
	 * Clears the screen
	 * 
	 * @return none
	 */
	void Clear();

};

#endif