#pragma once

#include "Render_Listener.h"
#include "Managers/Shader_Manager.h"
#include "Managers/Texture_Manager.h"

namespace OpenGL
{
	class TextureRenderer : public Render_Listener
	{
	public:
		TextureRenderer();

		virtual void notifyBeginFrame(RenderOptions* renderOptions);
		virtual void notifyDisplayFrame();
		virtual void notifyReshape(int width, int height);
		virtual void Initialize();

		virtual void notifyDestroy();
		virtual void notifyDestroyAll();

	protected:
		Managers::Shader_Manager* _shader_manager;
		Managers::Texture_Manager* _texture_manager;
		void SetUpVaoBuffer();
		GLuint vao, ebo;
	};
}