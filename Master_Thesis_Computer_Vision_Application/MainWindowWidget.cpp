#include "MainWindowWidget.h"
#include <QGroupBox>
#include <QPushButton>
#include <QCheckBox>
#include "OpenGL\Texture_Viewer.h"

using namespace OpenGL;

MainWindowWidget::MainWindowWidget(QWidget* parent)
	:QWidget(parent)
{

}

void MainWindowWidget::Initialize()
{
	InitializeLayout();
	InitializetextureGroupBox();
	InitializeButtonGroupBox();

}

void MainWindowWidget::InitializeLayout()
{
	_main_layout = new QHBoxLayout(this);

	_texture_layout = new QVBoxLayout();
	//_texture_layout->addStretch(1);
	QGroupBox* texture_group_box = new QGroupBox("texture viewerer");
	_main_layout->addWidget(texture_group_box);
	texture_group_box->setLayout(_texture_layout);

	_button_layout = new QVBoxLayout();
	_button_layout->addStretch(1);
	QGroupBox * button_group_box = new QGroupBox("buttons");
	_main_layout->addWidget(button_group_box);
	button_group_box->setLayout(_button_layout);

}

void MainWindowWidget::InitializeButtonGroupBox()
{
	QPushButton* color_space_button = new QPushButton("Benchmark Color Spaces");
	QPushButton* random_button_2 = new QPushButton("Random button 2");
	QPushButton* random_button_3 = new QPushButton("Random button 3");
	QPushButton* random_button_4 = new QPushButton("Random button 4");
	QPushButton* random_button_5 = new QPushButton("Random button 5");
	_button_layout->addWidget(color_space_button);
	_button_layout->addWidget(random_button_2);
	_button_layout->addWidget(random_button_3);
	_button_layout->addWidget(random_button_4);
	_button_layout->addWidget(random_button_5);
	

	connect(color_space_button, SIGNAL(pressed()), this, SLOT(OpenColorSpaceViewer()));

}

void MainWindowWidget::OpenColorSpaceViewer()
{
	ColorSpaceWindow* colorSpaceWindow = new ColorSpaceWindow(this);
	colorSpaceWindow->Initialize();
	colorSpaceWindow->show();
}

void MainWindowWidget::InitializetextureGroupBox()
{
	QCheckBox* checkBox = new QCheckBox();
	checkBox->setText("Use RGB texture (nRGB deselected)");
	checkBox->setCheckable(true);
	checkBox->setChecked(true);
	_texture_layout->addWidget(checkBox);

	OpenGL::RenderOptions* renderOptions = new OpenGL::RenderOptions();

	OpenGL::Texture_Viewer* texture_viewer = new OpenGL::Texture_Viewer(this);
	OpenGL::Render_Listener* listener = new OpenGL::BenchmarkTextureRenderer();
	texture_viewer->Initialize();
	texture_viewer->SetListener(listener);
	texture_viewer->SetRenderOptions(renderOptions);
	_texture_layout->addWidget(texture_viewer);

	connect(checkBox, SIGNAL(toggled(bool)), texture_viewer, SLOT(ChangeBenchmarkTexture(bool)));
}