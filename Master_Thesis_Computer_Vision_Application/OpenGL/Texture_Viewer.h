#pragma once

#include "Render_Listener.h"
#include <QGLWidget>


namespace OpenGL
{
	class Texture_Viewer : public QGLWidget
	{
		Q_OBJECT
	public:
		Texture_Viewer(QWidget* parent = 0);

		void SetListener(Render_Listener* render_listener);
		void Initialize();

		void resizeGL(int width, int height) override;
		void paintGL() override;

		void SetRenderOptions(RenderOptions* renderOptions);


		RenderOptions* _render_options;

	private:
		Render_Listener* _render_listener;
		void DrawListener();
		void ReshapeListener();

		public slots:
		void ChangeBenchmarkTexture(bool rgb);
		void OnClose();
		void OnCloseAll();
		


	};
}
