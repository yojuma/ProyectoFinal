#include "personaje.h"


Personaje::Personaje(QObject *parent)
    : QObject{parent}, posX{70}, posY{70}
{
    rowPixmap = 0;
    colPixmap = 0;
    width = 108.25/3;
    height = 36.0625;
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
    QPixmap scaled = stripe->scaled(QSize(108.25, 144.25));
    painter->drawPixmap(0, 0, scaled, colPixmap, rowPixmap, width, height);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Personaje::moveLeft(){
    rowPixmap = 36.0625;
    colPixmap += width;
    if(colPixmap >= 108.25){
        colPixmap = 0;
    }
    posX -= 10;
    setPos(posX, posY);
}

void Personaje::moveRight(){
    rowPixmap = 72.125;
    colPixmap += width;
    if(colPixmap >= 108.25){
        colPixmap = 0;
    }
    posX += 10;
    setPos(posX, posY);
}

void Personaje::moveUp(){
    rowPixmap = 108.1875;
    colPixmap += width;
    if(colPixmap >= 108.25){
        colPixmap = 0;
    }
    posY -= 10;
    setPos(posX, posY);
}

void Personaje::moveDown(){
    rowPixmap = 0;
    colPixmap += width;
    if(colPixmap >= 108.25){
        colPixmap = 0;
    }
    posY += 10;
    setPos(posX, posY);
}



