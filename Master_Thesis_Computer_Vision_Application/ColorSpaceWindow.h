#pragma once

#include "OpenGL\Texture_Viewer.h"

#include <QMainWindow>
#include "ColorSpaceWidget.h"

class ColorSpaceWindow : public QMainWindow
{
	Q_OBJECT
public:
	ColorSpaceWindow(QWidget* parent = 0);
	void Initialize();

protected:
	void closeEvent(QCloseEvent* event);

private:
	ColorSpaceWidget* colorSpaceWidget;

signals:
	void WindowClosing();

};