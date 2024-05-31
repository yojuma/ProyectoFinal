#include "bomba.h"
#include "explosion.h"
#include <mainwindow.h>
#include <QGraphicsScene>

Bomba::Bomba(qreal x, qreal y, QGraphicsItem *parent){
    Q_UNUSED(parent);
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
    QTimer::singleShot(2000, this, &Bomba::detonate);

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

void Bomba::detonate() {
    createExplosion(x(), y()); // Centro
    createExplosion(x() - 50, y()); // Izquierda
    createExplosion(x() + 63, y()); // Derecha
    createExplosion(x(), y() - 50); // Arriba
    createExplosion(x(), y() + 50); // Abajo
    scene()->removeItem(this);
    delete this;
}

void Bomba::createExplosion(qreal x, qreal y){
    QList<QGraphicsItem *> items = scene()->items(QRectF(x, y, 50, 50));
    for (QGraphicsItem *item : items){
        if (dynamic_cast<Solidos*>(item) != nullptr){
            return;
        }
        if (Destruibles *destruible = dynamic_cast<Destruibles*>(item)){
            scene()->removeItem(destruible);
            this->deleteLater();
        }
        if (Enemigo *enemigo = dynamic_cast<Enemigo*>(item)){
            scene()->removeItem(enemigo);
            this->deleteLater();
        }
    }
    auto explosion = new Explosion(x, y);
    scene()->addItem(explosion);
}
