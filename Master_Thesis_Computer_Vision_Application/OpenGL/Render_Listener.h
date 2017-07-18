#pragma once

#include "glew.h"
#include "RenderOptions.h"

namespace OpenGL
{
	class Render_Listener
	{
	public:
		// Create render options
		virtual void notifyBeginFrame(RenderOptions* render_options) = 0;
		virtual void notifyDisplayFrame() = 0;
		virtual void notifyReshape(int width, int height) = 0;
		//virtual void notifyReshape(int x, int y, int width, int height)= 0;
		virtual void Initialize() = 0;

		virtual void notifyDestroy() = 0;
		virtual void notifyDestroyAll() = 0;

	};
}