#include "ColorSpaceWindow.h"

ColorSpaceWindow::ColorSpaceWindow(QWidget* parent)
	:QMainWindow(parent)
{

}

void ColorSpaceWindow::Initialize()
{
	colorSpaceWidget = new ColorSpaceWidget(this);
	this->setCentralWidget(colorSpaceWidget);

	colorSpaceWidget->Initialize();
}

void ColorSpaceWindow::closeEvent(QCloseEvent* event)
{
	emit WindowClosing();
}