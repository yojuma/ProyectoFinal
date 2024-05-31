#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class Explosion : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Explosion();
    explicit Explosion(qreal x, qreal y, QObject *parent = nullptr);
    void createExplosion(qreal x, qreal y);
    QRectF boundingRect() const;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
public slots:
    void destroyExplosion();
    void actualizarExplosion();
private:

    QTimer* timer;
    QPixmap* stripe;
    qreal rowPixmap, colPixmap, width, height, posX, posY;
    bool direccion;
};


#endif // EXPLOSION_H
