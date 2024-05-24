#ifndef DESTRUIBLES_H
#define DESTRUIBLES_H

#include <QObject>
#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QTimer>

class Destruibles : public QObject, public QGraphicsItem{
public:
    explicit Destruibles(QObject *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
    QPixmap* stripe;
    qreal rowPixmap, colPixmap, width, height, posX, posY;
};

#endif // DESTRUIBLES_H
