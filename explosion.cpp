#include "explosion.h"
#include <QGraphicsScene>
#include "mainwindow.h"

Explosion::Explosion(qreal x, qreal y,QObject *parent)
    : QObject{parent}
{
    rowPixmap = 0;
    colPixmap = 0;
    width = 62;
    height = 53;
    setPos(x,y);
    stripe = new QPixmap(":/imagenes/explosion.png");
    timer = new QTimer;
    timer->start(120);
    connect(timer, SIGNAL(timeout()), this, SLOT(actualizarExplosion()));
    QTimer::singleShot(500, this, &Explosion::destroyExplosion);
}

void Explosion::actualizarExplosion(){
    update(0, 0, width, height);
}

QRectF Explosion::boundingRect() const{
    return QRectF(0, 0, width, height);
}

void Explosion::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    QPixmap scaled = stripe->scaled(QSize(62, 52));
    painter->drawPixmap(0, 0, scaled, colPixmap, rowPixmap, width, height);
    //painter->setBrush(Qt::transparent);
    //painter->drawRect(boundingRect());
    Q_UNUSED(option);
    Q_UNUSED(widget);
}


void Explosion::destroyExplosion() {
    scene()->removeItem(this);
    delete this;
}
