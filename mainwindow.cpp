#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPointF>
#include <QRectF>
#include <QtDebug>
#include <QLabel>
#include <QMessageBox>
#include <QMediaPlayer>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    //----------crear menu principal----------
    ui->setupUi(this);
    menuPrincipal = new QGraphicsScene(this);
    menuPrincipal->setSceneRect(0, 0, 1069, 807); // Tamaño del menú principal
    ui->graphicsView->setScene(menuPrincipal);
    ui->graphicsView->resize(menuPrincipal->width()+5, menuPrincipal->height()+5);
    this->resize(ui->graphicsView->width()+9, ui->graphicsView->height()+29);
    auto background = QImage(":/imagenes/menu_back.png");
    auto scaledBack = background.scaled(1069,807);
    ui->graphicsView->setBackgroundBrush(scaledBack); // Ajustar tamaño y posición de la imagen

    //----------musica----------
    playlist = new QMediaPlaylist();
    player = new QMediaPlayer(this);

    playlist->addMedia(QUrl("qrc:/audio/musica_menu.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    player->setPlaylist(playlist);
    player->setVolume(10);
    player->play();
}

void MainWindow::crearNivel(){
    //--------Crea y agrega los elementos del menu inicial--------
    ui->setupUi(this);

    personaje = new Personaje;

    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 1069, 807);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->resize(scene->width()+5, scene->height()+5);
    this->resize(ui->graphicsView->width()+20, ui->graphicsView->height()+100);
    auto background = QImage(":/imagenes/fondoJuego.jpg");
    auto scaledBack = background.scaled(1071,810);
    ui->graphicsView->setBackgroundBrush(scaledBack);

    //--------musica nivel-------
    playlist1 = new QMediaPlaylist();
    player1 = new QMediaPlayer(this);
    playlist1->addMedia(QUrl("qrc:/audio/musica_juego.mp3"));
    playlist1->setPlaybackMode(QMediaPlaylist::Loop);

    player1->setPlaylist(playlist1);
    player1->setVolume(10);
    player1->play();


    //---------añadir personaje y bloques fijos-----------
    scene->addItem(personaje);
    personaje->setPos(70,70);

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
            newX -= 5;
        } else if (event->key() == Qt::Key_D) {
            newX += 5;
        } else if (event->key() == Qt::Key_W) {
            newY -= 5;
        } else if (event->key() == Qt::Key_S) {
            newY += 5;
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
            } else if(event->key() == Qt::Key_Space){
                qreal x = personaje->getPosX()+5;
                qreal y = personaje->getPosY()+5;
                if(bombas==1){
                    auto exp = new Bomba(x, y);
                    scene->addItem(exp);
                    exp->setPos(x,y);
                    bombas++;

                }



            }
        }
    }
}


bool MainWindow::collidesWithObjects(qreal x, qreal y) {
    QRectF rect(x, y, personaje->boundingRect().width(), personaje->boundingRect().height());
    QList<QGraphicsItem *> items = ui->graphicsView->scene()->items(rect);

    for (QGraphicsItem *item : items) {
        if (item != personaje && dynamic_cast<Bomba*>(item) == nullptr) {
            return true; // Existe una colisión con otro objeto
        }
    }
    return false; // No hay colisiones con otros objetos
}

void MainWindow::on_ButtomPlay_clicked(){
    QMessageBox msgBox;
    msgBox.setText("Bienvenido al juego de Bombman.\n"
                   "Controlarás tu personaje con WASD y space para agregar las bombas.\n"
                   "Tendrás 5 minutos para acabar con tus enemigos.\n"
                   "Good Luck!");
    msgBox.exec();
    crearNivel();
    ui->ButtomPlay->hide();
    menuPrincipal->clear();
    player->stop();
    delete player;
    delete playlist;
}

