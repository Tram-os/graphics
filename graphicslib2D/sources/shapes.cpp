#include "shapes.h"
#include "shader.h"
#include "vertexarray.h"
#include "vertexbuffer.h"
#include "indexbuffer.h"

#include <glew.h>
#include <SDL_opengl.h>
#include <gl\glu.h>

Shapes::Shapes()
{
	Shader program = Shader("sources/shaders/vertex.vs", "sources/shaders/fragment.fs");
	ID = program.ID;
	glUseProgram(ID);
	posLocation = glGetAttribLocation(ID, "aPos");
	colorLocation = glGetUniformLocation(ID, "inputColor");
	glUniform4f(colorLocation, 1, 1, 1, 1); // set default color to white
}

void Shapes::drawRect(const Point2D& min, const Point2D& max, const ColorRGBA& color) const
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

	glUseProgram(ID);

	// Create vertex array
	VertexArray va = VertexArray();

	// Create vertex buffer
	VertexBuffer vb = VertexBuffer(vertices, sizeof(vertices));

	VertexBufferLayout layout;
	layout.Push<float>(3);
	
	va.AddBuffer(vb, layout);

	IndexBuffer indexBuffer = IndexBuffer(indices, 4);

	glUniform4f(colorLocation, color.r, color.g, color.b, color.a);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
}

void Shapes::fillRect(const Point2D& min, const Point2D& max, const ColorRGBA& color) const
{
	// The four vertices of the rectangle
	float vertices[] = {
		min.x, min.y, 0,
		min.x, max.y, 0,
		max.x, max.y, 0,
		max.x, min.y, 0
	};
	unsigned int indices[] = {
		0, 1, 2, // top left triangle
		0, 3, 2  // bottom right triangle
	};

	glUseProgram(ID);

	// Create and set all the buffer objects
	GLuint VAO;
	glGenVertexArrays(1, &VAO);

	// bind the vertex array first
	glBindVertexArray(VAO);

	// set buffers
	VertexBuffer vb = VertexBuffer(vertices, sizeof(vertices));
	IndexBuffer ib = IndexBuffer(indices, 6);

	glVertexAttribPointer(posLocation, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(posLocation);

	glUniform4f(colorLocation, color.r, color.g, color.b, color.a);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

