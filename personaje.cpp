#include "personaje.h"


Personaje::Personaje(QObject *parent)
    : QObject{parent}, posX{70}, posY{60}
{
    rowPixmap = 0;
    colPixmap = 0;
    width = (433/3)/3;
    height = (577/3)/4;
    stripe = new QPixmap(":/imagenes/personaje.png");
}


void Personaje::actualizarPersonaje(){
    update(0, 0, width, height);
}

QRectF Personaje::boundingRect() const{
    return QRectF(0, 0, width, height);

}

void Personaje::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    QPixmap scaled = stripe->scaled(QSize(433/3, 577/3));
    painter->drawPixmap(0, 0, scaled, colPixmap, rowPixmap, width, height);
    //painter->setBrush(Qt::transparent);
    //painter->drawRect(boundingRect());
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Personaje::moveLeft(){
    rowPixmap = (577/3)/4;
    colPixmap += width;
    if(colPixmap >= 433/3){
        colPixmap = 0;
    }
    posX -= 5;
    setPos(posX, posY);
}

void Personaje::moveRight(){
    rowPixmap = (577/3)/2;
    colPixmap += width;
    if(colPixmap >= 433/3){
        colPixmap = 0;
    }
    posX += 5;
    setPos(posX, posY);
}

void Personaje::moveUp(){
    rowPixmap = 144.2475;
    colPixmap += width;
    if(colPixmap >= 433/3){
        colPixmap = 0;
    }
    posY -= 5;
    setPos(posX, posY);
}

void Personaje::moveDown(){
    rowPixmap = 0;
    colPixmap += width;
    if(colPixmap >= 433/3){
        colPixmap = 0;
    }
    posY += 5;
    setPos(posX, posY);
}

qreal Personaje::getPosX(){
    return posX;
}
qreal Personaje::getPosY(){
    return posY;
}

