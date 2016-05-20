#ifndef BALL_H
#define BALL_H


/********************* HEADER FILES***************************/

#include <QGraphicsItem>
#include <QObject> //We add QObject whenever we want to use signal and slots
#include "obsticles_inside_scene.h"
#include <QList>
#include "score.h"



class Ball :public QObject,public QGraphicsItem
{
    // In order to handle signal and slot we add a macro / Q_OBJECT
    Q_OBJECT

public:
    //Public Member Variables
    qreal object_speed;
    qreal spacePress_Move;
    qreal spaceRelease_Move;
    QBrush ballColor;
    Score *playerScore;
    QRectF rec;


    //Constructors and Destructors
    Ball();
    ~Ball(){}

    //Member Functions
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


    //SLOTS
public slots:
    void advance(int phase);
    void spacePressed_Slot();
    void spaceReleased_Slot();



};

#endif // BALL_H
