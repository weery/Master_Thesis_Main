#include "TextureRenderer.h"


#include "VertexFormat.h"
#include <vector>

#include <iostream>

using namespace OpenGL;

TextureRenderer::TextureRenderer() 
{
	glEnable(GL_TEXTURE_2D);
	
}

void TextureRenderer::Initialize() 
{
	_shader_manager = new Managers::Shader_Manager();
	_shader_manager->Initialize();

	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
		std::cout << "shader loading" << error << std::endl;

	_texture_manager = new Managers::Texture_Manager();
	_texture_manager->Initialize();
	error = glGetError();
	if (error != GL_NO_ERROR)
		std::cout << "texture loading" << error << std::endl;

	SetUpVaoBuffer();
}


void TextureRenderer::notifyBeginFrame(RenderOptions* renderOptions)
{
	GLuint program;
	program = _shader_manager->GetShaderProgram("colorTexturedShader");
	glUseProgram(program);

	GLuint texture;



	texture = _texture_manager->GetTexture(renderOptions->GetTextureName());
	glActiveTexture(GL_TEXTURE0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	//glUniform1i(glGetUniformLocation(program, "texture1"), 0);
}

void TextureRenderer::SetUpVaoBuffer()
{
	std::vector<OpenGL::VertexFormat> vertices;
	vertices.push_back(VertexFormat(glm::vec3(-1, -1, 0), glm::vec2(0, 0)));
	vertices.push_back(VertexFormat(glm::vec3(-1, 1, 0), glm::vec2(0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(1, 1, 0), glm::vec2(1, 1)));
	vertices.push_back(VertexFormat(glm::vec3(1, -1, 0), glm::vec2(1, 0)));

	std::vector<GLuint> indices;
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);

	indices.push_back(0);
	indices.push_back(2);
	indices.push_back(3);


	GLuint vbo;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat)*vertices.size(),
		&vertices[0], GL_STATIC_DRAW);

	// VERTICES
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat),
		(GLvoid*)(offsetof(VertexFormat, VertexFormat::position)));

	// Texture 
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat),
		(GLvoid*)(offsetof(VertexFormat, VertexFormat::textureCoordinates)));

	glGenBuffers(1, &ebo);
	// Bind index buffer to corresponding target
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	// ititialize index buffer, allocate memory, fill it with data
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*indices.size(), &indices[0], GL_STATIC_DRAW);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}

void TextureRenderer::notifyDisplayFrame() 
{
	glClearColor(0, 0, 0, 1.0);
	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
		std::cout << "Error Now " << error << std::endl;
	glClear(GL_COLOR_BUFFER_BIT);
	error = glGetError();
	if (error != GL_NO_ERROR)
		std::cout << "Error Now -1" << error << std::endl;
	
	glBindVertexArray(vao);
	error = glGetError();
	if (error != GL_NO_ERROR)
		std::cout << "Error Now 0 " << error << std::endl;
	// bind index buffer if you want to render indexed data
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	error = glGetError();
	if (error != GL_NO_ERROR)
		std::cout << "Error Now 2" << error << std::endl;
	// indexed draw call
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
	error = glGetError();
	if (error != GL_NO_ERROR)
		std::cout << "Error Now 3" << error << std::endl;
}
void TextureRenderer::notifyReshape(int width, int height) 

{
	glViewport(0,0,width,height);
}

void TextureRenderer::notifyDestroy()
{
	_texture_manager->~Texture_Manager();
}

void TextureRenderer::notifyDestroyAll()
{
	_texture_manager->DestroyAll();
}