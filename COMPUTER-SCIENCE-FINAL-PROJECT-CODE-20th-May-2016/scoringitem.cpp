#include "scoringitem.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QTimer>

scoringitem::scoringitem():QObject(),QGraphicsPixmapItem()
{

    //Creating a ball or Ellipse
    setPixmap(QPixmap(":/Images/blueball"));
    setScale(0.3);
    //setPos(370,245);
    point_increase_obst = 0;


    //setPos(width()/2-10,height()-190);
    // qDebug()<<"Scoreadder added";



}

void scoringitem::advance(int phase)
{

    setPos( x(), point_increase_obst + y());


    if( pos().y()  > 480  )
    {
        scene()->removeItem(this);
        delete this;
        //qDebug()<<"Ball deleted";
    }

}

void scoringitem::spacePressed_Increase_Score_Slot()
{
    point_increase_obst  = 2 ;
}

void scoringitem::spaceReleased_Increase_Score_Slot()
{
    point_increase_obst  = 0 ;
}
