#include "obsticles_inside_rect.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"


/*
obsticles_inside_rect::obsticles_inside_rect()
{
    object_angle = (180);
    setRotation(object_angle);
    object_speed = 2 ;
    int startX =120;
    int startY =120;
    setPos(mapToParent(startX,startY));


}

void obsticles_inside_rect::QGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec= boundingRect();
    QBrush brush = (Qt::black);
    if(scene()->collidingItems(this).isEmpty())
    {
        brush.setColor(Qt::yellow);
    }
        else
    {
    //when collusion
        brush.setColor(Qt::blue);
       //DoCollsion();

    }
    painter->fillRect(rec, brush);
    painter->drawRect(rec);

}

QRectF obsticles_inside_rect::QGraphicsItem::boundingRect() const
{
    return QRect(0,0,30,30);
}

void obsticles_inside_rect::advance(int phase)
{
    if(!phase) return;
    QPointF location = this->pos();
    setPos(mapToParent(0,-(object_speed)));
}
*/
/*void obsticles_inside_rect::DoCollsion()
{

    setRotation(rotation()+180 );

//set if the new position is i bounds
   QPointF newpoint = mapToParent(-(boundingRect().width()),-(boundingRect().width()+2));
   if (!scene()->sceneRect().contains((newpoint)))
   {


       //move it back in bounce
      newpoint = mapToParent(0,0);


   }

   else
   {

       //set the new position
   setPos(newpoint);

   }
}
*/
