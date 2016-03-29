#include "items_inside_rect.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

Items_inside_Rect::Items_inside_Rect()
{
    //Random starting rotatation

    object_angle = (180);
    setRotation(object_angle);
    //Set the Speed
    object_speed = 2 ;
    //Random starting Position

    int startX =100;
    int startY =100;

/*
    if(qrand() % 1)
    {
        startX = (qrand()% 200);
        startY = (qrand()% 200);
    }
    else
    {
        startX = (qrand()% -100);
        startY = (qrand()% -100);
    }
*/
    setPos(mapToParent(startX,startY));
}

/*Items_inside_Rect::Items_inside_Rect()
{
    object_angle = (90);
    setRotation(object_angle);
     object_speed = 2 ;
     int startX =50;
     int startY =50;
     setPos(mapToParent(startX,startY));

}
/*
Items_inside_Rect::Item2_inside_Rect()
{

    object_angle = (180);
    setRotation(object_angle);
    object_speed = 0 ;
    int startX =120;
    int startY =120;
    setPos(mapToParent(startX,startY));
}
*/
QRectF Items_inside_Rect::boundingRect() const
{

    return QRect(0,0,30,30);

}
/*
QRectF Items_inside_Rect::boundingRect2() const
{
      return QRect(0,0,30,30);
}
*/
void Items_inside_Rect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec= boundingRect();
    QBrush brush = (Qt::black);
    // brush.setColor(Qt::yellow);
    //painter->fillRect(rec, brush);
    //painter->drawRect(rec);


   //basic collusion deteaction
    if(scene()->collidingItems(this).isEmpty())
    {
    //when no collusion
        brush.setColor(Qt::yellow);
    }
        else
    {
    //when collusion
        brush.setColor(Qt::blue);
       Hitting_border();

    }
    painter->fillRect(rec, brush);
    painter->drawRect(rec);


}
/*
void Items_inside_Rect::paint2(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
       Hitting_border();

    }
    painter->fillRect(rec, brush);
    painter->drawRect(rec);

}
*/
void Items_inside_Rect::advance(int phase)
{
    if(!phase) return;
    QPointF location = this->pos();
    setPos(mapToParent(0,-(object_speed)));
}
/*
void Items_inside_Rect::advance2(int phase)
{
    if(!phase) return;
    QPointF location2 = this->pos();
    setPos(mapToParent(0,-(object_speed)));
}
*/
void Items_inside_Rect::Hitting_border()
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
/*
void Items_inside_Rect::Hitting_border2()
{

    setRotation(rotation()+180 );

//set if the new position is i bounds
   QPointF newpoint = mapToParent(-(boundingRect2().width()),-(boundingRect2().width()+2));
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
