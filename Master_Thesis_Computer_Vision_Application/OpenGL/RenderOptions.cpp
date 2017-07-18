#include "RenderOptions.h"


using namespace OpenGL;

RenderOptions::RenderOptions()
{
	_benchmark_use_rgb = true;
	_texture_name = "";
	channels[0] = 0;
	channels[1] = 1;
	channels[2] = 2;
}

QString RenderOptions::GetTextureName() 
{
	return _texture_name;
}

bool RenderOptions::UseRgbBenchmarkTexture() 
{
	return _benchmark_use_rgb;
}

int * RenderOptions::GetChannels()
{
	return channels;
}

bool RenderOptions::UsingThreeChannels()
{
	return threeChannels;
}

void RenderOptions::ChangeBenchmarkTexture(bool use_rgb)
{
	if (_benchmark_use_rgb != use_rgb)
	{
		_benchmark_use_rgb = use_rgb;
		emit RenderOptionsUpdated();
	}
}

void RenderOptions::ChangeTextureName(QString textureName)
{
	if (_texture_name != textureName)
	{
		_texture_name = textureName;
		emit RenderOptionsUpdated();
	}
}

void RenderOptions::setChannel(bool toggled)
{
	if (toggled)
	{
		QString objectName = sender()->objectName();
		QStringList colorIndex = objectName.split(".");
		ColorSpaceIndices colorSpaceIndex = (ColorSpaceIndices)colorIndex.at(0).toInt();
		int channelindex = colorIndex.at(1).toInt();
		channels[channelindex] = colorSpaceIndex;
	}
	emit RenderOptionsUpdated();
}
void RenderOptions::useThreeChannels(bool toggled)
{
	threeChannels = toggled;
	emit RenderOptionsUpdated();
}