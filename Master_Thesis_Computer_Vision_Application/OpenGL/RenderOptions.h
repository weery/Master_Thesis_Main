#pragma once

#include <QObject>
#include <QString>

namespace OpenGL
{
	enum ColorSpaceIndices
	{
		RGB_RED,
		RGB_GREEN,
		RGB_BLUE,
		HSI_HUE,
		HSI_SATURATION,
		HSI_INTENSITY,
		SAVI_GREEN,
		SAVI_BLUE,
		NDVI_GREEN,
		NDVI_BLUE,
		MSAVI_GREEN,
		MSAVI_BLUE,
		MSAVI2_GREEN,
		MSAVI2_BLUE,
		NUMBER_OF_INDICES,
	};

	inline const QString ColorSpaceIndexTostring(const ColorSpaceIndices index)
	{
		switch (index)
		{
		case RGB_RED:
			return "RGB - red";
			break;
		case RGB_BLUE:
			return "RGB - blue";
			break;
		case RGB_GREEN:
			return "RGB - green";
			break;
		case HSI_HUE:
			return "HSI - hue";
			break;
		case HSI_SATURATION:
			return "HSI - saturation";
			break;
		case HSI_INTENSITY:
			return "HSI - intensity";
			break;
		case SAVI_GREEN:
			return "SAVI - green";
			break;
		case SAVI_BLUE:
			return "SAVI - blue";
			break;
		case NDVI_GREEN:
			return "NDVI - green";
			break;
		case NDVI_BLUE:
			return "NDVI - blue";
			break;
		case MSAVI_GREEN:
			return "MSAVI - green";
			break;
		case MSAVI_BLUE:
			return "MSAVI - blue";
			break;
		case MSAVI2_GREEN:
			return "MSAVI2 - green";
			break;
		case MSAVI2_BLUE:
			return "MSAVI2 - blue";
			break;
		default:
			return "Not defined";
			break;
		}
	}
	class RenderOptions : public QObject
	{
		Q_OBJECT
	public:
		RenderOptions();

		QString GetTextureName();
		bool UseRgbBenchmarkTexture();
		int* GetChannels();
		bool UsingThreeChannels();

	private:
		bool _benchmark_use_rgb;
		QString _texture_name;

		int channels[3] = { 0,0,0 };
		bool threeChannels = true;

	signals:
		void RenderOptionsUpdated();

		public slots:
		void ChangeBenchmarkTexture(bool rgb);
		void ChangeTextureName(QString textureName);

		void setChannel(bool toggled);
		void useThreeChannels(bool toggled);
	};
}