#ifndef SITEM_H
#define SITEM_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
class SItem : public QGraphicsItem
{
public:
    SItem();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void advance(int phase);

private:
    qreal angle;
    qreal speed;
    void DoCollision();
};

#endif // SITEM_H


