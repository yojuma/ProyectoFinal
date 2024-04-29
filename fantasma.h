// objetofantasma.h
#ifndef OBJETOFANTASMA_H
#define OBJETOFANTASMA_H

#include <QObject>
#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QTimer>

class Fantasma : public QObject, public QGraphicsItem{
    Q_OBJECT
public:
    explicit Fantasma(QObject *parent = nullptr);


    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void moveJump();


public slots:
    void actualizarPersonaje();

private:
    QTimer* timer;
    QPixmap* stripe;
    qreal rowPixmap, colPixmap, width, height, posX, posY;
};

#endif // OBJETOFANTASMA_H
