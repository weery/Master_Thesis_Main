#pragma once

#include "TextureRenderer.h"

namespace OpenGL
{
	class BenchmarkTextureRenderer : public TextureRenderer
	{
	public:
		BenchmarkTextureRenderer();

	protected:
		virtual void notifyBeginFrame(RenderOptions* renderOptions);
	};
}

