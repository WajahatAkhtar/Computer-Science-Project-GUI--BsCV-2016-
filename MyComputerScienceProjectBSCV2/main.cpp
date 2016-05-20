#include <QtGui/QApplication>
#include "gamemainwindow.h"




int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    GameMainWindow w; //Creating instance of mainWindow
    w.setWindowTitle("PIN THE BALL");
    // w.start();
    //w.diplayGameWindow();
    w.show();//Showing mainWindow


    return a.exec();
}
