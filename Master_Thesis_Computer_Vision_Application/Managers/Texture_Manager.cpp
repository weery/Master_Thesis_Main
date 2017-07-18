#include "Texture_Manager.h"

#include <iostream>
#include <fstream>

using namespace Managers;

//const QString Texture_Manager::TextureResourceLocation =
//"d:/programming/Master_Thesis/Master_Thesis_Computer_Vision_Application/Resources/Images/";

const QString Texture_Manager::TextureResourceLocation =
	"./Resources/Images/";

std::map<QString, GLuint> Texture_Manager::_texture_maps;
std::map<QString, QImage> Texture_Manager::_image_maps;
GLuint Texture_Manager::_benchmark_rgb;
GLuint Texture_Manager::_benchmark_nrgb;
bool Texture_Manager::_initialized;

QImage Texture_Manager::_benchmark_image_rgb;
QImage Texture_Manager::_benchmark_image_nrgb;

Texture_Manager::Texture_Manager()
{

}

Texture_Manager::~Texture_Manager()
{
	

	_initialized = false;
}

void Texture_Manager::DestroyAll()
{
	std::map<QString, GLuint>::iterator i;
	for (i = _texture_maps.begin(); i != _texture_maps.end(); i++)
	{
		GLuint texture = i->second;
		glDeleteTextures(1, &texture);
	}
	_texture_maps.clear();
	glDeleteTextures(1, &_benchmark_rgb);
	glDeleteTextures(1, &_benchmark_nrgb);
}

void Texture_Manager::Initialize()
{
	glewInit();
	// TODO: change to png
	QString rgb_texture_location = TextureResourceLocation + "rgb.jpg";
	QString nrgb_texture_location = TextureResourceLocation + "nrgb.jpg";

	_benchmark_rgb = LoadAndCreateTexture(rgb_texture_location,_initialized);
	_benchmark_nrgb = LoadAndCreateTexture(nrgb_texture_location,_initialized);
	_initialized = true;
}

GLuint Texture_Manager::LoadAndCreateTexture(QString filename, bool loadImage)
{
	GLuint texture_object;
	glGenTextures(1, &texture_object);
		glBindTexture(GL_TEXTURE_2D, texture_object);
		// Maybe include mipmapping?
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		float maxAnisotropy;
		glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maxAnisotropy);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, maxAnisotropy);

		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		QImage map =  QImage(filename);
		
		map = map.mirrored(false, true);
		int width = map.width();
		int height = map.height();
		
		if (map.isNull())
			std::cout << "Error loading " << filename.toStdString() << std::endl;
		else
			std::cout << " Texture loaded, Width " << width << ", Height " << height << std::endl;

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, map.bits());
	
	// if mipmapping
	// glGenerateMipmap(GL_TEXTURE_2D);

	return texture_object;
}


bool Texture_Manager::LoadTexture(QString fileName, QString textureName)
{
	if (_texture_maps.find(textureName) == _texture_maps.end())
	{
		std::cout << "Texture " << textureName.toStdString() << " already loaded " << std::endl;
		return false;
	}
	GLuint texture = LoadAndCreateTexture(fileName,true);

	_texture_maps[textureName] = texture;
	return true;
}


GLuint Texture_Manager::GetBenchmarkTexture(bool rgb)
{
	return (rgb ? _benchmark_rgb : _benchmark_nrgb);
}

GLuint Texture_Manager::GetTexture(QString textureName)
{
	if (_texture_maps.find(textureName) != _texture_maps.end())
	{
		return _texture_maps[textureName];
	}

	std::cout << "Texture " << textureName.toStdString() << " not loaded" << std::endl;
	return -1;
}