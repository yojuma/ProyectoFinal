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
    Bomba(qreal x, qreal y, QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
    void setInitialPosition(qreal, qreal);
    qreal getPosX();
    qreal getPosY();
    void detonate();
public slots:
    void actualizar();
private:
    void createExplosion(qreal x, qreal y);
    QTimer* timer;
    QTimer* timerExp;
    qreal posX, posY, rowPixmap, colPixmap, width, height;
    QPixmap* stripe;
};

#endif // BOMBA_H
