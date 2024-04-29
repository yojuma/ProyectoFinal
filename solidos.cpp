#include "solidos.h"
Solidos::Solidos(QObject *parent)
    : QObject{parent}, posX{0}, posY{0}
{
    rowPixmap = 0;
    colPixmap = 0;
    width = 63;
    height = 54;
    stripe = new QPixmap(":/bmpSolido.png");
}

QRectF Solidos::boundingRect() const{
    return QRectF(0, 0, width, height);
}

void Solidos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QPixmap scaled = stripe->scaled(QSize(63,54));
    painter->drawPixmap(0,0, scaled, colPixmap, rowPixmap, width, height);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
