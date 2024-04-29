#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPointF>
#include <QRectF>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    personaje = new Personaje;
    Fantasma *fantasma= new Fantasma;
    fantasma = new Fantasma;


    scene->setSceneRect(0, 0, 1200, 700);
    scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
    ui->graphicsView->setScene(scene);
    ui->graphicsView->resize(scene->width()+5, scene->height()+5);
    this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);
    auto background = QImage(":/fondoJuego.jpg");
    auto scaledBack = background.scaled(1071,810);
    ui->graphicsView->setBackgroundBrush(scaledBack);

    scene->addItem(personaje);
    //scene->addItem(fantasma);
    personaje->setPos(70,70);
    //fantasma->setPos(600,520);

    for(int j=0;j<filas;j++){
        switch (j) {
        case 0:{
            for(int i=54;i<900;i+=54){
                cuadrosSolidos = new Solidos;
                scene->addItem(cuadrosSolidos); //borde izquierdo
                cuadrosSolidos->setPos(0,i);
            }
                for(int i =63;i<1071;i+=63){
                    cuadrosSolidos = new Solidos;
                    scene->addItem(cuadrosSolidos); //borde inferior
                    cuadrosSolidos->setPos(i,757);
                }
        }
        case 1:{
            for(int i =0;i<1071;i+=63){
                cuadrosSolidos = new Solidos;
                scene->addItem(cuadrosSolidos); //borde superior
                cuadrosSolidos->setPos(i,0);
            }
        }
        case 2:{
            for(int i =126;i<1008;i+=126){
                cuadrosSolidos = new Solidos;   //primer fila bloques solidos
                scene->addItem(cuadrosSolidos);
                cuadrosSolidos->setPos(i,108);
            }
        }
        case 3:{
            for(int i =126;i<1008;i+=126){
                cuadrosSolidos = new Solidos;   //segunda fila bloques solidos
                scene->addItem(cuadrosSolidos);
                cuadrosSolidos->setPos(i,216);
            }
        }
        case 4:{
            for(int i =126;i<1008;i+=126){
                cuadrosSolidos = new Solidos;   //tercera fila bloques solidos
                scene->addItem(cuadrosSolidos);
                cuadrosSolidos->setPos(i,324);
            }
        }
        case 5:{
            for(int i =126;i<1008;i+=126){
                cuadrosSolidos = new Solidos;   //cuarta fila bloques solidos
                scene->addItem(cuadrosSolidos);
                cuadrosSolidos->setPos(i,432);
            }
        }
        case 6:{
            for(int i =126;i<1008;i+=126){
                cuadrosSolidos = new Solidos;   //quinta fila bloques solidos
                scene->addItem(cuadrosSolidos);
                cuadrosSolidos->setPos(i,540);
            }
        }
        case 7:{
            for(int i =126;i<1008;i+=126){
                cuadrosSolidos = new Solidos;   //sexta fila bloques solidos
                scene->addItem(cuadrosSolidos);
                cuadrosSolidos->setPos(i,648);
            }
        }
        case 8:{
            for(int i=54;i<900;i+=54){
                cuadrosSolidos = new Solidos;
                scene->addItem(cuadrosSolidos); //borde derecho
                cuadrosSolidos->setPos(1008,i);
            }
        }
    }
    }

}


MainWindow::~MainWindow()
{
    delete personaje;
    delete scene;
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (personaje != nullptr) {
        qreal newX = personaje->x();
        qreal newY = personaje->y();

        if (event->key() == Qt::Key_A) {
            newX -= 10;
        } else if (event->key() == Qt::Key_D) {
            newX += 10;
        } else if (event->key() == Qt::Key_W) {
            newY -= 10;
        } else if (event->key() == Qt::Key_S) {
            newY += 10;
        }

        if (!collidesWithObjects(newX, newY)) {
            if (event->key() == Qt::Key_A) {
                personaje->moveLeft();
            } else if (event->key() == Qt::Key_D) {
                personaje->moveRight();
            } else if (event->key() == Qt::Key_W) {
                personaje->moveUp();
            } else if (event->key() == Qt::Key_S) {
                personaje->moveDown();
            }
        }
    }
}


bool MainWindow::collidesWithObjects(qreal x, qreal y) {
    QRectF rect(x, y, personaje->boundingRect().width(), personaje->boundingRect().height());
    QList<QGraphicsItem *> items = ui->graphicsView->scene()->items(rect);

    foreach(QGraphicsItem *item, items) {
        if (item != personaje) {
            return true; // Existe una colisión con otro objeto
        }
    }
    return false; // No hay colisiones con otros objetos
}





