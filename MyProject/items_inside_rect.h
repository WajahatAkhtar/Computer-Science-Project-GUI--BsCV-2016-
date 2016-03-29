#ifndef ITEMS_INSIDE_RECT_H
#define ITEMS_INSIDE_RECT_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>



class Items_inside_Rect: public :: QGraphicsItem
{

public:
    Items_inside_Rect();
    //Item2_inside_Rect();

    //~Items_inside_Rect();

    QRectF boundingRect()const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    //QPixmap image;
protected :
     void advance(int phase);


private :
     qreal object_angle;
     qreal object_speed;
     void Hitting_border();


};

#endif // ITEMS_INSIDE_RECT_H
