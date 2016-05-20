#include "player.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include "ball.h"
#include <QObject>



Player::Player()
{
    setPixmap(QPixmap(":/Images/clicktoplay"));
    setScale(0.15);
    //Setting Position of the player
    setPos(x()+360,y()+540);
}




void Player::keyPressEvent(QKeyEvent *event)
{
    //Key From keyboard is Pressed
    if(event->key() == Qt::Key_Space)
    {
        emit spacePressed();

    }

}




void Player::keyReleaseEvent(QKeyEvent *event)
{
    //Key From keyboard is Pressed
    if(event->key() == Qt::Key_Space)
    {
        emit spaceReleased();

    }

}






void Player::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if(event->button() == Qt::LeftButton)
    {

        emit clickPressed();
        qDebug()<<"Clicked";

    }

}








void Player::mouseReleaseEvent(QGraphicsSceneMouseEvent *event2)
{
    if(event2->button() == Qt::LeftButton){

        emit clickReleased();
        qDebug()<<"Released";

    }
}




//void Player::advance(int phase)
//{
//    setPos(x(),y()+2);
//}











