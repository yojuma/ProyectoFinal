#ifndef BOMBA_H
#define BOMBA_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class Bomba : public QObject, public QGraphicsItem{
    Q_OBJECT
public:
    Bomba(qreal, qreal);
    QRectF boundingRect() const;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
    void setInitialPosition(qreal, qreal);
    qreal getPosX();
    qreal getPosY();
public slots:
    void actualizar();
private:
    QTimer* timer;
    qreal posX, posY, rowPixmap, colPixmap, width, height;
    QPixmap* stripe;
};

#endif // BOMBA_H
