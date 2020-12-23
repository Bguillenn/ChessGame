#include "mainwindow.h"

#include <QApplication>
#include "GameController.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = new MainWindow;

    GameController* gameController = GameController::getInstance();

    QObject::connect(gameController, SIGNAL(updateGameData()), w, SLOT(handleUpdateGameData()));

    w->show();
    return a.exec();
}
