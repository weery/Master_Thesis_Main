#include "Texture_Viewer.h"

using namespace OpenGL;

Texture_Viewer::Texture_Viewer(QWidget* parent)
	:QGLWidget(parent)
{
	setAutoBufferSwap(false);
	setMinimumWidth(400);
}

void Texture_Viewer::SetRenderOptions(RenderOptions* renderOptions)
{
	_render_options = renderOptions;
}

void Texture_Viewer::SetListener(Render_Listener* render_listener)
{
	_render_listener = render_listener;
	_render_listener->Initialize();

}

void Texture_Viewer::Initialize() 
{
	glInit();

	glewInit();
}

void Texture_Viewer::resizeGL(int width, int height)
{
	ReshapeListener();
}

void Texture_Viewer::paintGL()
{
	DrawListener();
}

void Texture_Viewer::DrawListener()
{
	if (_render_listener)
	{
		_render_listener->notifyBeginFrame(_render_options);
		_render_listener->notifyDisplayFrame();
		makeCurrent();
		swapBuffers();
	}
}

void Texture_Viewer::ReshapeListener()
{
	if (_render_listener)
	{
		QSize size = this->size();
		_render_listener->notifyReshape(size.width(),size.height());
	}
}


void Texture_Viewer::ChangeBenchmarkTexture(bool rgb)
{
	_render_options->ChangeBenchmarkTexture(rgb);
	DrawListener();
}


void Texture_Viewer::OnClose()
{
	if (_render_listener)
	{
		_render_listener->notifyDestroy();
		_render_listener = NULL;
	}
}

void Texture_Viewer::OnCloseAll()
{
	if (_render_listener)
	{
		_render_listener->notifyDestroyAll();
		_render_listener->notifyDestroy();
		_render_listener = NULL;
	}
}