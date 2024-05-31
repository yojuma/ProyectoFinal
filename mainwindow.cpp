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
#include <QMediaPlaylist>


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

    //-----------------musica-------------------
    playlist = new QMediaPlaylist();
    player = new QMediaPlayer(this);
    playlist->addMedia(QUrl("qrc:/audio/musica_menu.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    player->setPlaylist(playlist);
    player->setVolume(0);
    player->play();
}


void MainWindow::crearNivel(){
    //--------Crea y agrega los elementos del menu inicial--------
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 1069, 807);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->resize(scene->width()+5, scene->height()+5);
    this->resize(ui->graphicsView->width()+220, ui->graphicsView->height()+50);
    auto background = QImage(":/imagenes/fondoJuego.jpg");
    auto scaledBack = background.scaled(1071,810);
    ui->graphicsView->setBackgroundBrush(scaledBack);

    //--------musica nivel-------
    /*
    playlist1 = new QMediaPlaylist();
    player1 = new QMediaPlayer(this);
    playlist1->addMedia(QUrl("qrc:/audio/musica_juego.mp3"));
    playlist1->addMedia(QUrl("qrc:/audio/musica_juego.mp3"));
    playlist1->setPlaybackMode(QMediaPlaylist::Loop);
    player1->setPlaylist(playlist1);
    player1->setVolume(0);
    player1->play();*/

    //---------añadir personaje y enemigos-----------
    personaje = new Personaje;
    scene->addItem(personaje);
    personaje->setPos(70,60);

    switch(enemigos){
    case 0:
        enemigo1 = new Enemigo;
        scene->addItem(enemigo1);
        enemigo1->setPos(963,708);
        enemigo1->setPosX(963);
        enemigo1->setPosY(708);
        enemigos++;
    case 1:
        enemigo2 = new Enemigo;
        scene->addItem(enemigo2);
        enemigo2->setPos(963,58);
        enemigo2->setPosX(963);
        enemigo2->setPosY(58);
        enemigos++;
    }
    //----------------------------
    timerEnemigo = new QTimer;
    timerEnemigo->start(200);
    connect(timerEnemigo, &QTimer::timeout, this, &MainWindow::checkCollisionEnemigo);

    //-------añadir bloques solidos---------
    for(int j=0;j<filas;j++){
        switch (j){
        case 0:{
            //--------borde izquierdo solidos-------
            for(int i=54;i<900;i+=54){
                cuadrosSolidos = new Solidos;
                scene->addItem(cuadrosSolidos);
                cuadrosSolidos->setPos(0,i);
                bSolidos.push_back(cuadrosSolidos);
            }
            //------------borde inferior solidos-------------
            for(int i =63;i<1071;i+=63){
                cuadrosSolidos = new Solidos;
                scene->addItem(cuadrosSolidos);
                cuadrosSolidos->setPos(i,757);
                bSolidos.push_back(cuadrosSolidos);
            }
        }
        case 1:{
            //------------borde superior solidos------------
            for(int i =0;i<1071;i+=63){
                cuadrosSolidos = new Solidos;
                scene->addItem(cuadrosSolidos);
                cuadrosSolidos->setPos(i,0);
                bSolidos.push_back(cuadrosSolidos);
            }
        }
        case 2:{
            //------primer fila bloques solidos-----------
            for(int i =126;i<1008;i+=126){
                cuadrosSolidos = new Solidos;
                scene->addItem(cuadrosSolidos);
                cuadrosSolidos->setPos(i,108);
                bSolidos.push_back(cuadrosSolidos);
            }
        }
        case 3:{
            //-------segunda fila bloques solidos---------
            for(int i =126;i<1008;i+=126){
                cuadrosSolidos = new Solidos;
                scene->addItem(cuadrosSolidos);
                cuadrosSolidos->setPos(i,216);
                bSolidos.push_back(cuadrosSolidos);
            }
        }
        case 4:{
            //--------tercera fila bloques solidos---------
            for(int i =126;i<1008;i+=126){
                cuadrosSolidos = new Solidos;
                scene->addItem(cuadrosSolidos);
                cuadrosSolidos->setPos(i,324);
                bSolidos.push_back(cuadrosSolidos);
            }
        }
        case 5:{
            //--------cuarta fila bloques solidos-------
            for(int i =126;i<1008;i+=126){
                cuadrosSolidos = new Solidos;
                scene->addItem(cuadrosSolidos);
                cuadrosSolidos->setPos(i,432);
                bSolidos.push_back(cuadrosSolidos);
            }
        }
        case 6:{
            //-------quinta fila bloques solidos---------
            for(int i =126;i<1008;i+=126){
                cuadrosSolidos = new Solidos;
                scene->addItem(cuadrosSolidos);
                cuadrosSolidos->setPos(i,540);
                bSolidos.push_back(cuadrosSolidos);
            }
        }
        case 7:{
            //--------sexta fila bloques solidos--------
            for(int i =126;i<1008;i+=126){
                cuadrosSolidos = new Solidos;
                scene->addItem(cuadrosSolidos);
                cuadrosSolidos->setPos(i,648);
                bSolidos.push_back(cuadrosSolidos);
            }
        }
        case 8:{
            //-------------borde derecho solidos---------
            for(int i=54;i<900;i+=54){
                cuadrosSolidos = new Solidos;
                scene->addItem(cuadrosSolidos);
                cuadrosSolidos->setPos(1008,i);
                bSolidos.push_back(cuadrosSolidos);
            }
        }
        }
    }
    //---------añadir bloques destruibles--------
    for(int d=1;d<filas;d++){
        switch(d){
        case 1:{
            //--------fila 1 bloques destruibles--------
            int a = 1+rand() % 10;
            for(int i=189;i<505;i+=63*a){
                cuadrosDestruibles = new Destruibles;
                scene->addItem(cuadrosDestruibles);
                cuadrosDestruibles->setPos(i,54);
                bDestruibles.push_back(cuadrosDestruibles);
            }
        }
        case 2:{
            //--------fila 2 bloques destruibles--------
            for(int i=189;i<820;i+=63*2){
                cuadrosDestruibles = new Destruibles;
                scene->addItem(cuadrosDestruibles);
                cuadrosDestruibles->setPos(i,108);
                bDestruibles.push_back(cuadrosDestruibles);
            }
        }
        case 3:{
            //--------fila 3 bloques destruibles--------
            int b = 1+rand() % 10;
            for(int i=63;i<946;i+=63*b){
                cuadrosDestruibles = new Destruibles;
                scene->addItem(cuadrosDestruibles);
                cuadrosDestruibles->setPos(i,162);
                bDestruibles.push_back(cuadrosDestruibles);
            }
        }
        case 4:{
            //--------fila 4 bloques destruibles--------
            for(int i=189;i<946;i+=63*2){
                cuadrosDestruibles = new Destruibles;
                scene->addItem(cuadrosDestruibles);
                cuadrosDestruibles->setPos(i,216);
                bDestruibles.push_back(cuadrosDestruibles);
            }
        }
        case 5:{
            //--------fila 5 bloques destruibles--------
            int c = 1+rand() % 10;
            for(int i=63;i<946;i+=63*c){
                cuadrosDestruibles = new Destruibles;
                scene->addItem(cuadrosDestruibles);
                cuadrosDestruibles->setPos(i,270);
                bDestruibles.push_back(cuadrosDestruibles);
            }
        }
        case 6:{
            //--------fila 6 bloques destruibles--------
            for(int i=189;i<946;i+=63*2){
                cuadrosDestruibles = new Destruibles;
                scene->addItem(cuadrosDestruibles);
                cuadrosDestruibles->setPos(i,324);
                bDestruibles.push_back(cuadrosDestruibles);
            }
        }
        case 7:{
            //--------fila 7 bloques destruibles--------
            int d = 1+rand() % 10;
            for(int i=63;i<946;i+=63*d){
                cuadrosDestruibles = new Destruibles;
                scene->addItem(cuadrosDestruibles);
                cuadrosDestruibles->setPos(i,378);
                bDestruibles.push_back(cuadrosDestruibles);
            }
        }
        case 8:{
            //--------fila 8 bloques destruibles--------
            for(int i=189;i<946;i+=63*2){
                cuadrosDestruibles = new Destruibles;
                scene->addItem(cuadrosDestruibles);
                cuadrosDestruibles->setPos(i,432);
                bDestruibles.push_back(cuadrosDestruibles);
            }
        }
        case 9:{
            //--------fila 9 bloques destruibles--------
            int e = 1+rand() % 10;
            for(int i=63;i<946;i+=63*e){
                cuadrosDestruibles = new Destruibles;
                scene->addItem(cuadrosDestruibles);
                cuadrosDestruibles->setPos(i,486);
                bDestruibles.push_back(cuadrosDestruibles);
            }
        }
        case 10:{
            //--------fila 10 bloques destruibles--------
            for(int i=189;i<946;i+=63*2){
                cuadrosDestruibles = new Destruibles;
                scene->addItem(cuadrosDestruibles);
                cuadrosDestruibles->setPos(i,540);
                bDestruibles.push_back(cuadrosDestruibles);
            }
        }
        case 11:{
            //--------fila 11 bloques destruibles--------
            int f = 1+rand() % 10;
            for(int i=63;i<946;i+=63*f){
                cuadrosDestruibles = new Destruibles;
                scene->addItem(cuadrosDestruibles);
                cuadrosDestruibles->setPos(i,594);
                bDestruibles.push_back(cuadrosDestruibles);
            }
        }
        case 12:{
            //--------fila 12 bloques destruibles--------
            for(int i=189;i<820;i+=63*2){
                cuadrosDestruibles = new Destruibles;
                scene->addItem(cuadrosDestruibles);
                cuadrosDestruibles->setPos(i,648);
                bDestruibles.push_back(cuadrosDestruibles);
            }
        }
        case 13:{
            //--------fila 13 bloques destruibles--------
            int g = 1+rand() % 10;
            for(int i=189;i<505;i+=63*g){
                cuadrosDestruibles = new Destruibles;
                scene->addItem(cuadrosDestruibles);
                cuadrosDestruibles->setPos(i,702);
                bDestruibles.push_back(cuadrosDestruibles);
            }
        }
        }
    }
}


MainWindow::~MainWindow(){
    for (Bomba* bomba : nBombas) {
            delete bomba;
        }
        nBombas.clear();
    for (Solidos* solidos : bSolidos) {
            delete solidos;
        }
        bSolidos.clear();
    for (Destruibles* destruibles : bDestruibles) {
            delete destruibles;
        }
        bDestruibles.clear();
    delete personaje;
    delete enemigo1;
    delete enemigo2;
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
                qreal x = personaje->getPosX();
                qreal y = personaje->getPosY();
                if(bombas==1){
                    bomba = new Bomba(x, y);
                    nBombas.push_back(bomba);
                    scene->addItem(bomba);
                    bombas++;
                    bomba->setPos(x,y);
                    bombas--;

                }
            }
        }
    }
}


bool MainWindow::collidesWithObjects(qreal x, qreal y){
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
                   "Controlarás tu personaje con W,A,S,D y space para agregar las bombas.\n"
                   "Tendrás 5 minutos para acabar con tus enemigos.\n"
                   "Good Luck!");
    msgBox.exec();
    crearNivel();
    ui->ButtomPlay->hide();
    menuPrincipal->clear();
    player->stop();
    delete player;
    delete playlist;
    ui->contadorJuego->display(tiempo);
    connect(cronometro, &QTimer::timeout, this, &MainWindow::activarTimer);
    cronometro->start(1000);
}

void MainWindow::checkCollisionEnemigo(){
    for(auto e : bDestruibles){
        QList<QGraphicsItem*> colisiones = scene->collidingItems(e);
        if(!colisiones.isEmpty()){
            for(auto c : colisiones){
                Enemigo *choque = dynamic_cast<Enemigo *>(c);
                if(choque==enemigo1){
                    enemigo1->colision(true);
                }
                else{
                    enemigo1->colision(false);

                }
                if(choque==enemigo2){
                    enemigo2->colision(true);
                }
                else{
                    enemigo2->colision(false);

                }
            }
        }
    }
}

void MainWindow::activarTimer(){
    tiempo--;
    if(tiempo==499){
        tiempo=459;
    }
    else if(tiempo==399){
        tiempo=359;
    }
    else if(tiempo==299){
        tiempo=259;
    }
    else if(tiempo==199){
        tiempo=159;
    }
    else if(tiempo==99){
        tiempo=59;
    }
    ui->contadorJuego->display(tiempo);
    if(tiempo==0){
        if(puntos_jugador>puntos_enemigo1 && puntos_jugador>puntos_enemigo2){
            QMessageBox msgBox;
            msgBox.setText("Tiempo terminado.\n"
                           "El ganador es el jugador.");
            msgBox.exec();
            cronometro->stop();
            delete personaje;
            delete enemigo1;
            delete enemigo2;
            delete scene;
            delete ui;
        }
        else if(puntos_enemigo1>puntos_jugador && puntos_enemigo1>puntos_enemigo2){
            QMessageBox msgBox;
            msgBox.setText("Tiempo terminado.\n"
                           "El ganador es el enemigo 1.");
            msgBox.exec();
            cronometro->stop();
            delete personaje;
            delete enemigo1;
            delete enemigo2;
            delete scene;
            delete ui;
        }
        else if(puntos_enemigo2>puntos_jugador && puntos_enemigo2>puntos_enemigo1){
            QMessageBox msgBox;
            msgBox.setText("Tiempo terminado.\n"
                           "El ganador es el enemigo 2.");
            msgBox.exec();
            cronometro->stop();
            delete personaje;
            delete enemigo1;
            delete enemigo2;
            delete scene;
            delete ui;
        }
        else{
            QMessageBox msgBox;
            msgBox.setText("Tiempo terminado.\n"
                           "No hay ganador.");
            msgBox.exec();
            cronometro->stop();
            delete personaje;
            delete enemigo1;
            delete enemigo2;
            delete scene;
            delete ui;
        }

    }
}

void MainWindow::actualizarPuntaje(){
    puntos_jugador++;
}


