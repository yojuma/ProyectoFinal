#include "fantasma.h"

Fantasma::Fantasma(QObject *parent)
    : QObject{parent}, posX{0}, posY{0}
{
    rowPixmap = 0;
    colPixmap = 0;
    width = 60;
    height = 500;
    stripe = new QPixmap(":/fantasma.png");
    timer = new QTimer;
    //timer->start(200);

    connect(timer, &QTimer::timeout, this, &Fantasma::actualizarPersonaje);
}

QRectF Fantasma::boundingRect() const{
    return QRectF(0, 0, width, height);
}

void Fantasma::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QPixmap scaled = stripe->scaled(QSize(254,320));
    painter->drawPixmap(0,0, scaled, colPixmap, rowPixmap, width, height);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Fantasma::actualizarPersonaje() {
    update(0, 0, width, height);
}





