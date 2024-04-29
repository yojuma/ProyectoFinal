#include "personaje.h"

Personaje::Personaje(QObject *parent)
    : QObject{parent}, posX{60}, posY{70}
{
    rowPixmap = 0;
    colPixmap = 0;
    width = 50;
    height = 47.5;
    stripe = new QPixmap(":/personaje.png");
    timer = new QTimer;
    //timer->start(200);

    connect(timer, &QTimer::timeout, this, &Personaje::actualizarPersonaje);
}

void Personaje::actualizarPersonaje(){
    update(0, 0, width, height);
}

QRectF Personaje::boundingRect() const{
    return QRectF(0, 0, width, height);
}

void Personaje::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    QPixmap scaled = stripe->scaled(QSize(150, 190));
    painter->drawPixmap(0, 0, scaled, colPixmap, rowPixmap, width, height);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Personaje::moveLeft(){
    rowPixmap = 120;
    colPixmap += width;
    if(colPixmap >= 183.9){
        colPixmap = 0;
    }
    posX -= 10;
    setPos(posX, posY);
}

void Personaje::moveRight(){
    rowPixmap = 180;
    colPixmap += width;
    if(colPixmap >= 183.9){
        colPixmap = 0;
    }
    posX += 10;
    setPos(posX, posY);
}

void Personaje::moveUp(){
    rowPixmap = 240;
    colPixmap += width;
    if(colPixmap >= 183.9){
        colPixmap = 0;
    }
    posY -= 10;
    setPos(posX, posY);
}

void Personaje::moveDown(){
    rowPixmap = 0;
    colPixmap += width;
    if(colPixmap >= 183.9){
        colPixmap = 0;
    }
    posY += 10;
    setPos(posX, posY);
}

