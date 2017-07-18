#pragma once

#include <glew.h>
#include <QImage>
#include <QString>
#include <map>
#include <vector>

namespace Managers
{
	class Texture_Manager
	{
	public:
		Texture_Manager();
		~Texture_Manager();

		void DestroyAll();
		void Initialize();
		bool LoadImage(QString fileName, QString imageName);
		bool LoadTexture(QString fileName, QString imageName);
		GLuint GetTexture(QString textureName);
		QImage GetImage(QString imageName);
		GLuint GetBenchmarkTexture(bool rgb);

		static const QString TextureResourceLocation;
	private:
		static std::map<QString, GLuint> _texture_maps;
		static std::map<QString, QImage> _image_maps;
		GLuint LoadAndCreateTexture(QString fileName, bool loadImage);
		static GLuint _benchmark_rgb;
		static GLuint _benchmark_nrgb;
		static bool _initialized;
		static QImage _benchmark_image_rgb;
		static QImage _benchmark_image_nrgb;

	};
}