#include "renderer.h"

#include "glew.h"

Renderer::Renderer()
{

}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{
	shader.Bind();
	va.Bind();
	ib.Bind();
	glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
}


void Renderer::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}