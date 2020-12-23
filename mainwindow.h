#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "GameController.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    GameController* gameController;

    //Metodos
    void initLabels();

    //Metodo para actualizar data
    void updateTurnoLabel();
    void updateJugadasLabel();
    void updateNegrasCapturadas();
    void updateBlancasCapturadas();
    void updateHistorialTable();
    QPixmap* getPiecePixMap(int);
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updateGameData();

private:
    Ui::MainWindow *ui;
signals:
public slots:
    void handleUpdateGameData();
};
#endif // MAINWINDOW_H
