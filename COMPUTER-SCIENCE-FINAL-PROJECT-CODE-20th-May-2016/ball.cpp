#include "ball.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <QList>
#include <typeinfo>
#include "ball.h"
#include "player.h"
#include "score.h"
#include "scoringitem.h"
#include "gamemainwindow.h"
#include <QMessageBox>



Ball::Ball():QObject(),QGraphicsItem()
{

    object_speed = 0;
    spacePress_Move = 0;
    spaceRelease_Move = 0;
    ballColor = Qt::yellow;
    setPos(370,520);
    qDebug()<<"Ball created";
    playerScore = new Score();


    //Creating a ball or Ellipse
    //setPixmap(QPixmap(":/Images/blueball"));
    //setScale(0.3);
    //setPos(width()/2-10,height()-190);

}




QRectF Ball::boundingRect() const
{
    return QRectF(0,0,20,20);
}


void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    rec= boundingRect();
    painter->setBrush(ballColor);
    painter->drawEllipse(rec);

    Obsticles_Inside_Scene *obs;

    //FOR OBSTICLES COLLUSION

    if(!scene()->collidingItems(this).isEmpty())
    {

        QList<QGraphicsItem*> obstacleList=scene()->collidingItems(this);
        QList<QGraphicsItem*>::iterator obstacleIterator = obstacleList.begin();


        if (typeid(*(obstacleList[0])) == typeid(scoringitem))
        {

            //qDebug()<<"Collided with score adder ";
            scene()->addItem(playerScore);
            playerScore->count();
            scene()->removeItem((scoringitem*)(*obstacleIterator));
        }

        else if (typeid(*(obstacleList[0])) == typeid(Player))
        {

            //qDebug()<<"Collided  adder ";
        }



        else if (typeid(*(obstacleList[0])) == typeid(QGraphicsScene))
        {

            qDebug()<<"  adder adder ";
            if( this->pos().y() + this->rec.height() < 0  || this->pos().y()  > 600 + this->rec.height() )
            {
                scene()->removeItem(this);
                delete this;
                //qDebug()<<"Ball deleted";
            }
        }



        else{

            obs = (Obsticles_Inside_Scene*)(*obstacleIterator);
            if(ballColor.color()== obs->itempen.color() )
            {

                //qDebug()<<"matched";
                ballColor.setColor(Qt::yellow);
                painter->setBrush(ballColor);
                painter->drawEllipse(rec);

            }



            else {

                //QMessageBox::information(new QWidget, QString("Switch BALL "),QString("Time up. You lost !!!          "));
                //QGraphicsTextItem *text = new QGraphicsTextItem("WAJAHAT ");
                //text->setTextWidth(100);
                //QMessageBox(QMessageBox::Information, "Switch Ball", "Game Over !!!     ", QMessageBox::Ok).exec();
                scene()->removeItem(this);
                delete this;
            }
        }

    }

    else  if( pos().y() + rec.height() < 10  || pos().y()  > 600 + rec.height() )
    {
        scene()->removeItem(this);
        delete this;
        //qDebug()<<"Ball deleted";
    }





}




void Ball::advance(int phase)
{


    if(x() == 370 && y() >= 521 )
    {
        object_speed = 0;
        //qDebug()<<"Pose detected";
    }


    setPos(x(),y()+object_speed);

}






void Ball::spacePressed_Slot()
{

    if(x() == 370 && y() >= 521 )
    {
        object_speed = -4;
        //qDebug()<<"space pressed Again";
    }

    //qDebug()<<"space pressed ";
    object_speed = -4;
    //qDebug()<<" Y Position when space Pressed"<<scenePos().y();
    setPos(x(),y()+object_speed);

}







void Ball::spaceReleased_Slot()
{
    //qDebug()<<"space Released ";
    object_speed = 2;
    //qDebug()<<" Y Position when space released"<<y();

}
