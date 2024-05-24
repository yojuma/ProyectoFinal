#include "enemigo.h"

Enemigo::Enemigo(QObject *parent)
    : QObject{parent}
{
    rowPixmap = 0;
    colPixmap = 0;
    width = 180/4;
    height = 180/4;
    direccion=false;
    stripe = new QPixmap(":/imagenes/enemigo.png");
    timer = new QTimer;
    timer->start(120);
    connect(timer, SIGNAL(timeout()), this, SLOT(actualizarEnemigo()));
}


void Enemigo::actualizarEnemigo(){
    if(direccion){
        moveRight();
    }else{
        moveLeft();
    }
    checkCollision();
    update(0, 0, width, height);
}

QRectF Enemigo::boundingRect() const{
    return QRectF(0, 0, width, height);
}

void Enemigo::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    QPixmap scaled = stripe->scaled(QSize(180, 180));
    painter->drawPixmap(0, 0, scaled, colPixmap, rowPixmap, width, height);
    //painter->setBrush(Qt::transparent);
    //painter->drawRect(boundingRect());
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
qreal Enemigo::getPosX(){
    return posX;
}
qreal Enemigo::getPosY(){
    return posY;
}

void Enemigo::setPosX(float newX){
   posX=newX;
}

void Enemigo::setPosY(float newY){
    posY=newY;
}

void Enemigo::moveRight(){
    rowPixmap = 180/2;
    colPixmap += width;
    if(colPixmap >= 180){
        colPixmap = 0;
    }
    posX += 5;
    setPos(posX, posY);

}

void Enemigo::moveLeft(){
    rowPixmap = 180/4;
    colPixmap += width;
    if(colPixmap >= 180){
        colPixmap = 0;
    }
    posX -= 5;
    setPos(posX, posY);

}

void Enemigo::moveUp(){
    rowPixmap = 180;
    colPixmap += width;
    if(colPixmap >= 180){
        colPixmap = 0;
    }
    posY -= 5;
    setPos(posX, posY);

}

void Enemigo::moveDown(){
    rowPixmap = 0;
    colPixmap += width;
    if(colPixmap >= 180){
        colPixmap = 0;
    }
    posY += 5;
    setPos(posX, posY);

}

void Enemigo::checkCollision(){

    if(getPosX() > 970){
        direccion=false;
    }
    if(getPosX() < 63){
        direccion=true;
    }
}

void Enemigo::colision(bool colision){
    if(colision){
        if(direccion){
            direccion=false;
            actualizarEnemigo();
        }
        else{
            direccion=true;
            actualizarEnemigo();
        }
    }
}
