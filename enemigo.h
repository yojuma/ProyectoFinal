#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class Enemigo : public QObject, public QGraphicsItem{
    Q_OBJECT
public:
    explicit Enemigo(QObject *parent = nullptr);

    QRectF boundingRect() const;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
    qreal getPosX();
    qreal getPosY();
    void setPosX(float newX);
    void setPosY(float newY);
    void moveLeft();
    void moveRight();
    void checkCollision();
    void colision(bool colision);


public slots:
    void actualizarEnemigo();

private:
    QTimer* timer;
    QPixmap* stripe;
    qreal rowPixmap, colPixmap, width, height, posX, posY;
    bool direccion;
};

#endif // ENEMIGO_H
