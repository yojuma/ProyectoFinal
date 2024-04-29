#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class Personaje : public QObject, public QGraphicsItem{
    Q_OBJECT
public:
    explicit Personaje(QObject *parent = nullptr);

    QRectF boundingRect() const;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    QPainterPath shape() const {
        QPainterPath path;
        // Añade la forma del cuerpo del personaje al path
        path.addRect(0, 0, width, height);
        // Excluye la cabeza del path
        QRectF cabezaRect(0, -10, width, 10); // Suponiendo que la cabeza está sobre el cuerpo
        path.addRect(cabezaRect);
        return path;
    }

public slots:
    void actualizarPersonaje();
private:
    QTimer* timer;
    QPixmap* stripe;
    qreal rowPixmap, colPixmap, width, height, posX, posY;
};

#endif // PERSONAJE_H



