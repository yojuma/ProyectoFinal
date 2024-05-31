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
#include "explosion.h"


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
    int tiempo=500;
    int puntos_jugador=0;
    int puntos_enemigo1=0;
    int puntos_enemigo2=0;
    void jugar();
    void crearNivel();
    void activarTimer();
    void actualizarPuntaje();

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
    QTimer *cronometro= new QTimer(this);
    Bomba* bomba;
    Explosion* exp;
    Enemigo* enemigo1;
    Enemigo* enemigo2;
    QVector<Solidos*> bSolidos;
    QVector<Destruibles*> bDestruibles;
    QVector<Bomba*> nBombas;
    QTimer *timer;
    QTimer *timerEnemigo;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    QMediaPlayer *player1;
    QMediaPlaylist *playlist1;
};
#endif // MAINWINDOW_H

