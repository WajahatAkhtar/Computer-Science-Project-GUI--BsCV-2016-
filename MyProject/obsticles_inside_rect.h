#ifndef OBSTICLES_INSIDE_RECT_H
#define OBSTICLES_INSIDE_RECT_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>


class obsticles_inside_rect:public :: QGraphicsItem
{
public:
   // obsticles_inside_rect();
   // ~obsticles_inside_rect();


   // QRectF boundingRect()const;
   // ~boundingRect()const;
   // void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected :
     void advance(int phase);

private :
    // qreal obsticle_angle;
     //qreal obsticle_speed;
    // qreal object_angle;
     //qreal object_speed;
    // void  DoCollsion();





};

#endif // OBSTICLES_INSIDE_RECT_H
