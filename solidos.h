#ifndef SOLIDOS_H
#define SOLIDOS_H

#include <QObject>
#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QTimer>

class Solidos : public QObject, public QGraphicsItem{
    Q_OBJECT
public:
    explicit Solidos(QObject *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
    QPixmap* stripe;
    qreal rowPixmap, colPixmap, width, height, posX, posY;
};

#endif // SOLIDOS_H
