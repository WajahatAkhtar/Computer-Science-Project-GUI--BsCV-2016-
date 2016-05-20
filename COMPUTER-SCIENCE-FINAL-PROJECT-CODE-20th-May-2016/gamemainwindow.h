#ifndef GAMEMAINWINDOW_H
#define GAMEMAINWINDOW_H


/********************* HEADER FILES***************************/


#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QLayout>
#include <QTimer>
#include <QPushButton>
#include <QGraphicsSceneMouseEvent>
#include <QWidget>
#include <vector>
#include "player.h"
#include "ball.h"
#include "obsticles_inside_scene.h"
#include "score.h"
#include "scoringItem.h"
using namespace std;



namespace Ui {
class GameMainWindow;
}

class GameMainWindow : public QMainWindow
{


private:
    Q_OBJECT

    //Private Member Variables
    Ui::GameMainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsView  *view;
    QTimer *timer;
    QPushButton *Playgame_button;
    int  positionAdder ;


    //QPushButton *playAgain;

public:
    //Public Member Variables
    QHBoxLayout *layout1;
    QWidget *win1;
    Ball *ball;
    Ball *ball2;
    Player *user;
    Score *playerScore;


    //Obsticle Paths for whole Game;

    //Obsticle 1 paths;
    QPainterPath path1a;
    QPainterPath path1b;
    scoringitem *increaseScore1;

    //Obsticle 2 paths;
    QPainterPath path2a;
    QPainterPath path2b;
    scoringitem *increaseScore2;

    //Obsticle 3 paths;
    QPainterPath path3a;
    QPainterPath path3b;
    scoringitem *increaseScore3;

    //Obsticle 4 paths;
    QPainterPath path4a;
    QPainterPath path4b;
    scoringitem *increaseScore4;

    //Obsticle 5 paths;
    QPainterPath path5a;
    QPainterPath path5b;
    scoringitem *increaseScore5;

    //Obsticle 6 paths;
    QPainterPath path6a;
    QPainterPath path6b;
    scoringitem *increaseScore6;

    //Obsticle 7 paths;
    QPainterPath path7a;
    QPainterPath path7b;
    scoringitem *increaseScore7;

    //Obsticle 8 paths;
    QPainterPath path8a;
    QPainterPath path8b;
    scoringitem *increaseScore8;

    //Obsticle 9 paths;
    QPainterPath path9a;
    QPainterPath path9b;
    scoringitem *increaseScore9;

    //Obsticle 10 paths;
    QPainterPath path10a;
    QPainterPath path10b;
    scoringitem *increaseScore10;



    //Pointer to  Obsticle 1
    Obsticles_Inside_Scene *obst1a;
    Obsticles_Inside_Scene *obst1b;

    //Pointer to  Obsticle 2
    Obsticles_Inside_Scene *obst2a;
    Obsticles_Inside_Scene *obst2b;

    //Pointer to  Obsticle 3
    Obsticles_Inside_Scene *obst3a;
    Obsticles_Inside_Scene *obst3b;

    //Pointer to  Obsticle 4
    Obsticles_Inside_Scene *obst4a;
    Obsticles_Inside_Scene *obst4b;

    //Pointer to  Obsticle 5
    Obsticles_Inside_Scene *obst5a;
    Obsticles_Inside_Scene *obst5b;

    //Pointer to  Obsticle 6
    Obsticles_Inside_Scene *obst6a;
    Obsticles_Inside_Scene *obst6b;

    //Pointer to  Obsticle 7
    Obsticles_Inside_Scene *obst7a;
    Obsticles_Inside_Scene *obst7b;

    //Pointer to  Obsticle 8
    Obsticles_Inside_Scene *obst8a;
    Obsticles_Inside_Scene *obst8b;

    //Pointer to  Obsticle 9
    Obsticles_Inside_Scene *obst9a;
    Obsticles_Inside_Scene *obst9b;

    //Pointer to  Obsticle 10
    Obsticles_Inside_Scene *obst10a;
    Obsticles_Inside_Scene *obst10b;




    // Constructors
    explicit GameMainWindow(QWidget *parent = 0);

    // Destructors
    ~GameMainWindow();

    //Memver Function
    void gameOver();
    //void start();
    void diplayGameWindow(QString dispText);



public slots:

    void playgame(void);



};

#endif // GAMEMAINWINDOW_H
