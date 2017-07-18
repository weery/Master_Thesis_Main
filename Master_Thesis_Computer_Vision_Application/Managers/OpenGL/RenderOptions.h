#pragma once

#include <QObject>

namespace OpenGL
{
	class RenderOptions :public QObject
	{
		Q_OBJECT
	public: 
		RenderOptions();

	private:
		bool _benchmark_use_rgb = true;
		QString _texture_name;

	signals:
		void OptionsChanged();

		public slots:
		void ChangeBenchmarkTexture(bool rgb_texure);
		void ChangeBenchmarkTexture(QString newTextureName);
	};
}