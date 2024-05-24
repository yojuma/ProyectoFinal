#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "personaje.h"
#include "solidos.h"
#include "bomba.h"
#include "destruibles.h"
#include "enemigo.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    bool collidesWithObjects(qreal x, qreal y);
    ~MainWindow();
    void keyPressEvent(QKeyEvent*);
    void checkCollisionEnemigo();
    int bombas=1;
    int enemigos=0;
    void jugar();
    void crearNivel();


private slots:
    void on_ButtomPlay_clicked();

private:
    int filas=15;
    int columnas=17;



    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QGraphicsScene* menuPrincipal;
    Personaje* personaje;
    Solidos* cuadrosSolidos;
    Destruibles* cuadrosDestruibles;
    Bomba* bomba;
    Enemigo* enemigo1;
    Enemigo* enemigo2;
    Enemigo* enemigo3;
    QVector<Solidos*> bSolidos;
    QVector<Destruibles*> bDestruibles;
    QTimer *timer;
    QTimer *timerEnemigo;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    QMediaPlayer *player1;
    QMediaPlaylist *playlist1;
};
#endif // MAINWINDOW_H

