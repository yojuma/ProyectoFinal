#include "bomba.h"

Bomba::Bomba(qreal x, qreal y){
    posX = x;
    posY = y;
    rowPixmap = 0;
    colPixmap = 0;
    width = 44;
    height = 48;
    stripe = new QPixmap(":/imagenes/bomba.png");
    timer = new QTimer;
    timer->start(200);

    connect(timer, &QTimer::timeout, this, &Bomba::actualizar);
}

void Bomba::actualizar(){
    colPixmap += width;
    if(colPixmap >= 132){
        colPixmap = 0;
    }

    update(0, 0, width, height);
}

QRectF Bomba::boundingRect() const{
    return QRectF(0, 0, width, height);
}

void Bomba::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    QPixmap scaled = stripe->scaled(QSize(132, 48));
    painter->drawPixmap(0, 0, scaled, colPixmap, rowPixmap, width, height);
    painter->setBrush(Qt::transparent);
    painter->drawRect(boundingRect());
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Bomba::setInitialPosition(qreal a, qreal b){
    posX = a;
    posY = b;
    setPos(posX, posY);
}

qreal Bomba::getPosX(){
    return posX;
}
qreal Bomba::getPosY(){
    return posY;
}
