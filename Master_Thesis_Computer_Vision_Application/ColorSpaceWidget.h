#pragma once 

#include "OpenGL\BenchmarkTextureRenderer.h"
#include "OpenGL\Texture_Viewer.h"
#include "OpenGL\RenderOptions.h"
#include "OpenGL\Render_Listener.h"
#include <QWidget>
#include <QGroupBox>
#include <QBoxLayout>
#include <QCheckBox>
#include <QPushButton>
#include <QRadioButton>


class ColorSpaceWidget : public QWidget
{
	Q_OBJECT
public:
	ColorSpaceWidget(QWidget* parent = 0);

	void Initialize();

private:

	void InitializeLayout();
	void InitializeColorSpaceGroupBox(OpenGL::RenderOptions* renderOptions);
	void InitializeTextureGroupBox(OpenGL::RenderOptions* renderOptions);
	void SetUpColorSettingsGroup(QGroupBox * colorGroup,
		int index, OpenGL::RenderOptions* renderOptions);


	QBoxLayout* _main_layout;
	QBoxLayout* _button_layout;
	QBoxLayout* _texture_layout;

	signals:
	public slots:
	void TryOnClose();

	
signals:
	void CloseWidget();
	


};