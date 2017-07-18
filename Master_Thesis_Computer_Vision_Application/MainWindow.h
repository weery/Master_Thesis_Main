#pragma once

#include <QMainWindow>
#include "MainWindowWidget.h"


class MainWindow : public QMainWindow
{

public:
	MainWindow(QWidget* parent = 0);
	void Initialize();

private:
	MainWindowWidget* mainWindowWidget;

	
};