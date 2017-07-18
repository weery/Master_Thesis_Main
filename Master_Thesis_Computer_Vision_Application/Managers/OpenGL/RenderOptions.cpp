#include "RenderOptions.h"

using namespace OpenGL;


RenderOptions::RenderOptions()
{
}


void RenderOptions::ChangeBenchmarkTexture(bool rgb_texture)
{
	if (rgb_texture != _benchmark_use_rgb)
	{
		_benchmark_use_rgb = rgb_texture;
		emit OptionsChanged();
	}
}

void RenderOptions::ChangeBenchmarkTexture(QString newTextureName)
{
	if (_texture_name != newTextureName)
	{
		_texture_name = newTextureName;
		emit OptionsChanged();
	}
}