#include "BenchmarkTextureRenderer.h"

#include <iostream>
using namespace OpenGL;

BenchmarkTextureRenderer::BenchmarkTextureRenderer()
	:TextureRenderer()
{

}

void BenchmarkTextureRenderer::notifyBeginFrame(RenderOptions *renderOptions)
{
	GLuint program;
	program = _shader_manager->GetShaderProgram("colorTexturedShader");
	glUseProgram(program);

	GLuint texture;
	texture = _texture_manager->GetBenchmarkTexture(renderOptions->UseRgbBenchmarkTexture());
	glActiveTexture(GL_TEXTURE0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
		std::cout << "Error Now " << error << std::endl;

	int* channels = renderOptions->GetChannels();
	int channel1 = channels[0];
	int channel2 = channels[1];
	int channel3 = channels[2];

	glUniform3i(glGetUniformLocation(program, "colorSpaceUsage"), channel1,
		channel2,
		channel3);

	int threeChannels = (int)renderOptions->UsingThreeChannels();

	glUniform1i(glGetUniformLocation(program, "oneChannel"), threeChannels);
}