#pragma once 

#include "OpenGL\Render_Listener.h"
#include "OpenGL\BenchmarkTextureRenderer.h"
#include "OpenGL\RenderOptions.h"
#include <QWidget>
#include <QBoxLayout>

#include "ColorSpaceWindow.h"

class MainWindowWidget : public QWidget
{
	Q_OBJECT
public:
	MainWindowWidget(QWidget* parent = 0);
	void Initialize();

private:
	void InitializeLayout();
	void InitializeButtonGroupBox();
	void InitializetextureGroupBox();

	//Layouts
	QBoxLayout* _main_layout;
	QBoxLayout* _texture_layout;
	QBoxLayout* _button_layout;

	private slots:
	void OpenColorSpaceViewer();


};