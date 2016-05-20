#include "obsticles_inside_scene.h"
#include <QDebug>
#include <QTimer>

Obsticles_Inside_Scene::Obsticles_Inside_Scene():QObject(),QGraphicsItem()
{
    object_speed_obst = 0;
    rec = boundingRect();

    //connecting Qtimer with ball move slot but whenever we create a slot that cllass must be derived from Qobject its a rule.
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(rotateObj()));
    timer->start(1000);


}



void Obsticles_Inside_Scene::rotateObj()
{

    // setTransformOriginPoint(60, 60);
    translate(60, 60);
    rotate(90); //both work great rotate 90 and rotate 2
    //rotate(90);
    translate(-60, -60);

    //qDebug()<<"Concected timer Rotating";

}



void Obsticles_Inside_Scene::advance(int phase)
{

    setPos( x(), object_speed_obst + y());


    if( pos().y()  > 420  )
    {
        scene()->removeItem(this);
        delete this;
        //qDebug()<<"Ball deleted";
    }

}



void Obsticles_Inside_Scene::spacePressed_ObsticleSlot()
{

    object_speed_obst  = 2 ;


}


void Obsticles_Inside_Scene::spaceReleased_ObsticleSlot()
{

    object_speed_obst = 0 ;

}



QRectF Obsticles_Inside_Scene::boundingRect() const
{

    return QRect(0,0,120,120);
}




QPainterPath Obsticles_Inside_Scene::shape() const
{


    return customPath;

    //    QPainterPath path ;
    //    path.moveTo(boundingRect().width(),boundingRect().height()/2);
    //    path.arcTo(boundingRect(), 0, 55);
    //    path.moveTo(0,boundingRect().height()/2);
    //    path.arcTo(boundingRect(), 180, 55);
    //    path.addText(400,400,QFont(),QString("wajiiii") );
    //    path.addEllipse(boundingRect());

    //return path;

}


void Obsticles_Inside_Scene::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setRenderHint(QPainter::Antialiasing);
    itempen.setWidth(8);
    painter->setPen(itempen);
    painter->drawPath(shape());


}


