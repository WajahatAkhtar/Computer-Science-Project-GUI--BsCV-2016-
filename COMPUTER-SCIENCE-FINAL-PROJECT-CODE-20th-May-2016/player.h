#ifndef PLAYER_H
#define PLAYER_H

/********************* HEADER FILES***************************/

#include <QGraphicsPixmapItem>
#include "ball.h"


class Player : public QObject ,public QGraphicsPixmapItem {
    Q_OBJECT

public:
    //Public Member Variables

    //Constructors and Destructors
    Player();
    ~Player(){}

    //Member Functions
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event2);



public slots:
    //void advance(int phase);

signals:
    void spacePressed();
    void spaceReleased();
    void clickPressed();
    void clickReleased();



};

#endif // PLAYER_H


