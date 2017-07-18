#include "MainWindow.h"


MainWindow::MainWindow(QWidget* parent)
	:QMainWindow(parent)
{

}


void MainWindow::Initialize()
{
	mainWindowWidget = new MainWindowWidget(this);
	this->setCentralWidget(mainWindowWidget);

	mainWindowWidget->Initialize();
}