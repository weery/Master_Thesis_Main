#include <QApplication>
#include <QSplashscreen>
#include "MainWindow.h"

using namespace Qt;

int main(int argc, char *argv[])
{
	QApplication application(argc, argv);

	//QSplashScreen* splashScreen = new QSplashScreen(QPixmap(
	//	"D:/Programming/Master_Thesis/Master_Thesis_Computer_Vision_Application/Resources/Images/Splash.png"));
	

	QSplashScreen* splashScreen = new QSplashScreen(QPixmap(
		"./Resources/Images/Splash.png"));

	splashScreen->show();

	Alignment splashScreenMessageLocation = AlignRight | AlignBottom;

	splashScreen->showMessage("Initializing", splashScreenMessageLocation, white);

	MainWindow mainWindow = new MainWindow();
	mainWindow.Initialize();

	mainWindow.show();

	splashScreen->finish(&mainWindow);

	delete splashScreen;


	return application.exec();
}
