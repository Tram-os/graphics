#include "shapes.h"
#include "shader.h"
#include "vertexarray.h"
#include "vertexbuffer.h"
#include "indexbuffer.h"

#include <glew.h>
#include <SDL_opengl.h>
#include <gl\glu.h>

Shapes::Shapes()
	: m_Shader(Shader("sources/shaders/vertex.vs", "sources/shaders/fragment.fs"))
{
	m_Shader.Bind();
	m_Shader.SetUniform4f("inputColor", 1, 1, 1, 1);
}

void Shapes::drawRect(const Point2D& min, const Point2D& max, const ColorRGBA& color)
{
	// The four vertices of the rectangle
	float vertices[] = {
		min.x, min.y, 0,
		min.x, max.y, 0,
		max.x, max.y, 0,
		max.x, min.y, 0
	};
	unsigned int indices[] = {
		0, 1, 2, 3
	};

	m_Shader.Bind();

	// Create vertex array
	VertexArray va = VertexArray();

	// Create vertex buffer
	VertexBuffer vb = VertexBuffer(vertices, sizeof(vertices));

	VertexBufferLayout layout;
	layout.Push<float>(3);
	
	va.AddBuffer(vb, layout);

	IndexBuffer indexBuffer = IndexBuffer(indices, 4);

	m_Shader.SetUniform4f("inputColor", color.r, color.g, color.b, color.a);


	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
}

void Shapes::fillRect(const Point2D& min, const Point2D& max, const ColorRGBA& color)
{
	// The four vertices of the rectangle
	float vertices[] = {
		min.x, min.y,
		min.x, max.y,
		max.x, max.y,
		max.x, min.y
	};
	unsigned int indices[] = {
		0, 1, 2, // top left triangle
		0, 3, 2  // bottom right triangle
	};

	m_Shader.Bind();

	VertexArray va = VertexArray();

	VertexBuffer vb = VertexBuffer(vertices, sizeof(vertices));
	
	VertexBufferLayout layout;
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);

	IndexBuffer ib = IndexBuffer(indices, 6);

	m_Shader.SetUniform4f("inputColor", color.r, color.g, color.b, color.a);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

