#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "personaje.h"
#include "solidos.h"
#include "bomba.h"

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
    void DibujarMatriz();
    void generarMatriz();
    int bombas=1;
    void jugar();
    void crearNivel();

private slots:
    void on_ButtomPlay_clicked();

private:
    int filas=15;
    int columnas=17;

    int **matrizBidimensional = new int*[filas];

    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QGraphicsScene* menuPrincipal;
    Personaje* personaje;
    Solidos* cuadrosSolidos;
    Bomba* bomba;
    QTimer *timer;
};
#endif // MAINWINDOW_H

