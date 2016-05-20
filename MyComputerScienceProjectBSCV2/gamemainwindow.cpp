#include "gamemainwindow.h"
#include "ui_gamemainwindow.h"
#include <QDebug>

GameMainWindow::GameMainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::GameMainWindow)
{
    ui->setupUi(this);

    //Creating Scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    //scene->setBackgroundBrush(Qt::black);



    //Adding Scene to View
    view =new QGraphicsView(scene);
    view->setFixedSize(800,600);
    view->setRenderHint(QPainter::Antialiasing);
    view->setWindowTitle("PIN THE BALL");

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setBackgroundBrush(Qt::black);
    //view->show();


    //Push Button Play Game on Main Window]
    Playgame_button = new QPushButton("Play Game");
    //button->setMinimumSize(50,50);
    //button->setGeometry(20,20,20,20);
    win1 = new QWidget(this);
    layout1 = new QHBoxLayout();
    win1->setGeometry(QRect(0,0,100,100));
    layout1->addWidget(Playgame_button);
    win1->setLayout(layout1);
    connect(Playgame_button,SIGNAL(pressed()),this,SLOT(playgame()));

    //this->setItemIndexMethod(NoIndex);


    /*************************ITEMS IN THE SCENE*****************/

    // scene->addEllipse(400,1000,100,100,QPen(Qt::red),QBrush(Qt::gray));

    //Adding Player
    user = new Player();
    //Make rect focusable
    user->setFlag(QGraphicsItem::ItemIsFocusable);
    user->setFocus();
    //Adding Items to the scene
    scene->addItem(user);



    ball= new Ball();
    scene->addItem(ball);



    /*************************  Obsticle 1 created IN THE SCENE*****************/


    // Obsticle 2 created
    obst1a = new Obsticles_Inside_Scene();
    obst1a->setPos(330, 200  );
    obst1a->itempen.setColor(Qt::red);
    scene->addItem(obst1a);
    path1a.moveTo(obst1a->boundingRect().width(),obst1a->boundingRect().height()/2);
    path1a.arcTo(obst1a->boundingRect(), 0, 90);
    obst1a->customPath = path1a;

    // Obsticle 1 path b created
    obst1b = new Obsticles_Inside_Scene();
    obst1b->setPos(330, 200  );
    obst1b->itempen.setColor(Qt::blue);
    scene->addItem(obst1b);
    path1b.moveTo(obst1b->boundingRect().width()/2,0);
    path1b.arcTo(obst1b->boundingRect(), 90, 90);
    obst1b->customPath = path1b;

    //Obsticle Point score adder if sucessfully crossed
    increaseScore1 = new scoringitem();
    increaseScore1->setPos(370,245 );
    scene->addItem(increaseScore1);




    /*************************  Obsticle 2 created IN THE SCENE*****************/

    // Obsticle 2 created
    obst2a = new Obsticles_Inside_Scene();
    obst2a->setPos(330,-100 );
    obst2a->itempen.setColor(Qt::green);
    scene->addItem(obst2a);
    path2a.moveTo(obst2a->boundingRect().width(),obst2a->boundingRect().height()/2);
    path2a.arcTo(obst2a->boundingRect(), 0, 55);
    obst2a->customPath = path2a;

    // Obsticle 2 path b created
    obst2b = new Obsticles_Inside_Scene();
    obst2b->setPos(330,-100 );
    obst2b->itempen.setColor(Qt::yellow);
    scene->addItem(obst2b);
    path2b.moveTo(0,obst2b->boundingRect().height()/2);
    path2b.arcTo(obst2b->boundingRect(),180, 55);
    obst2b->customPath = path2b;

    //Obsticle Point score adder if sucessfully crossed
    increaseScore2 = new scoringitem();
    increaseScore2->setPos(370,-45 );
    scene->addItem(increaseScore2);


    /*************************  Obsticle 3 created IN THE SCENE*****************/

    // Obsticle 3 created
    obst3a = new Obsticles_Inside_Scene();
    obst3a->setPos(330,-400 );
    obst3a->itempen.setColor(Qt::green);
    scene->addItem(obst3a);
    path3a.moveTo(obst3a->boundingRect().width(),obst3a->boundingRect().height()/2);
    path3a.arcTo(obst3a->boundingRect(), 0, 55);
    obst3a->customPath = path3a;

    // Obsticle 3 path b created
    obst3b = new Obsticles_Inside_Scene();
    obst3b->setPos(330,-400 );
    obst3b->itempen.setColor(Qt::yellow);
    scene->addItem(obst3b);
    path3b.moveTo(0,obst3b->boundingRect().height()/2);
    path3b.arcTo(obst3b->boundingRect(),180, 55);
    obst3b->customPath = path3b;

    //Obsticle Point score adder if sucessfully crossed
    increaseScore3 = new scoringitem();
    increaseScore3->setPos(370,-345 );
    scene->addItem(increaseScore3);


    /*************************  Obsticle 4 created IN THE SCENE*****************/

    // Obsticle 4 created
    obst4a = new Obsticles_Inside_Scene();
    obst4a->setPos(330,-700 );
    obst4a->itempen.setColor(Qt::green);
    scene->addItem(obst4a);
    path4a.moveTo(obst4a->boundingRect().width(),obst4a->boundingRect().height()/2);
    path4a.arcTo(obst4a->boundingRect(), 0, 55);
    obst4a->customPath = path4a;

    // Obsticle 4 path b created
    obst4b = new Obsticles_Inside_Scene();
    obst4b->setPos(330,-700 );
    obst4b->itempen.setColor(Qt::yellow);
    scene->addItem(obst4b);
    path4b.moveTo(0,obst4b->boundingRect().height()/2);
    path4b.arcTo(obst4b->boundingRect(),180, 55);
    obst4b->customPath = path4b;

    //Obsticle Point score adder if sucessfully crossed
    increaseScore4 = new scoringitem();
    increaseScore4->setPos(370,-645 );
    scene->addItem(increaseScore4);


    /*************************  Obsticle 5 created IN THE SCENE*****************/

    // Obsticle 5 created
    obst5a = new Obsticles_Inside_Scene();
    obst5a->setPos(330, -1000 );
    obst5a->itempen.setColor(Qt::green);
    scene->addItem(obst5a);
    path5a.moveTo(obst5a->boundingRect().width(),obst5a->boundingRect().height()/2);
    path5a.arcTo(obst5a->boundingRect(), 0, 55);
    obst5a->customPath = path5a;

    // Obsticle 5 path b created
    obst5b = new Obsticles_Inside_Scene();
    obst5b->setPos(330,-1000 );
    obst5b->itempen.setColor(Qt::yellow);
    scene->addItem(obst5b);
    path5b.moveTo(0,obst5b->boundingRect().height()/2);
    path5b.arcTo(obst5b->boundingRect(),180, 55);
    obst5b->customPath = path5b;

    //Obsticle Point score adder if sucessfully crossed
    increaseScore5 = new scoringitem();
    increaseScore5->setPos(370,-945 );
    scene->addItem(increaseScore5);




    /*************************  Obsticle 6 created IN THE SCENE*****************/

    // Obsticle 6 created
    obst6a = new Obsticles_Inside_Scene();
    obst6a->setPos(330,-1300 );
    obst6a->itempen.setColor(Qt::green);
    scene->addItem(obst6a);
    path6a.moveTo(obst6a->boundingRect().width(),obst6a->boundingRect().height()/2);
    path6a.arcTo(obst6a->boundingRect(), 0, 55);
    obst6a->customPath = path6a;

    // Obsticle 6 path b created
    obst6b = new Obsticles_Inside_Scene();
    obst6b->setPos(330,-1300 );
    obst6b->itempen.setColor(Qt::yellow);
    scene->addItem(obst6b);
    path6b.moveTo(0,obst6b->boundingRect().height()/2);
    path6b.arcTo(obst6b->boundingRect(),180, 55);
    obst6b->customPath = path6b;

    //Obsticle Point score adder if sucessfully crossed
    increaseScore6 = new scoringitem();
    increaseScore6->setPos(370,-1245 );
    scene->addItem(increaseScore6);


    /*************************  Obsticle 7 created IN THE SCENE*****************/

    // Obsticle 7 created
    obst7a = new Obsticles_Inside_Scene();
    obst7a->setPos(330,-1600 );
    obst7a->itempen.setColor(Qt::green);
    scene->addItem(obst7a);
    path7a.moveTo(obst7a->boundingRect().width(),obst7a->boundingRect().height()/2);
    path7a.arcTo(obst7a->boundingRect(), 0, 55);
    obst7a->customPath = path7a;

    // Obsticle 7 path b created
    obst7b = new Obsticles_Inside_Scene();
    obst7b->setPos(330,-1600 );
    obst7b->itempen.setColor(Qt::yellow);
    scene->addItem(obst7b);
    path7b.moveTo(0,obst7b->boundingRect().height()/2);
    path7b.arcTo(obst7b->boundingRect(),180, 55);
    obst7b->customPath = path7b;

    //Obsticle Point score adder if sucessfully crossed
    increaseScore7 = new scoringitem();
    increaseScore7->setPos(370,-1545 );
    scene->addItem(increaseScore7);



    /*************************  Obsticle 8 created IN THE SCENE*****************/

    // Obsticle 8 created
    obst8a = new Obsticles_Inside_Scene();
    obst8a->setPos(330,-1900 );
    obst8a->itempen.setColor(Qt::green);
    scene->addItem(obst8a);
    path8a.moveTo(obst8a->boundingRect().width(),obst8a->boundingRect().height()/2);
    path8a.arcTo(obst8a->boundingRect(), 0, 55);
    obst8a->customPath = path8a;

    // Obsticle 8 path b created
    obst8b = new Obsticles_Inside_Scene();
    obst8b->setPos(330,-1900 );
    obst8b->itempen.setColor(Qt::yellow);
    scene->addItem(obst8b);
    path8b.moveTo(0,obst8b->boundingRect().height()/2);
    path8b.arcTo(obst8b->boundingRect(),180, 55);
    obst8b->customPath = path8b;

    //Obsticle Point score adder if sucessfully crossed
    increaseScore8 = new scoringitem();
    increaseScore8->setPos(370,-1845 );
    scene->addItem(increaseScore8);


    /*************************  Obsticle 9 created IN THE SCENE*****************/

    // Obsticle 9 created
    obst9a = new Obsticles_Inside_Scene();
    obst9a->setPos(330,-2200 );
    obst9a->itempen.setColor(Qt::green);
    scene->addItem(obst9a);
    path9a.moveTo(obst9a->boundingRect().width(),obst9a->boundingRect().height()/2);
    path9a.arcTo(obst9a->boundingRect(), 0, 55);
    obst9a->customPath = path9a;

    // Obsticle 9 path b created
    obst9b = new Obsticles_Inside_Scene();
    obst9b->setPos(330,-2500 );
    obst9b->itempen.setColor(Qt::yellow);
    scene->addItem(obst9b);
    path9b.moveTo(0,obst9b->boundingRect().height()/2);
    path9b.arcTo(obst9b->boundingRect(),180, 55);
    obst9b->customPath = path9b;

    //Obsticle Point score adder if sucessfully crossed
    increaseScore9 = new scoringitem();
    increaseScore9->setPos(370,-2145 );
    scene->addItem(increaseScore9);


    /*************************  Obsticle 10 created IN THE SCENE*****************/

    // Obsticle 10 created
    obst10a = new Obsticles_Inside_Scene();
    obst10a->setPos(330,-2500 );
    obst10a->itempen.setColor(Qt::green);
    scene->addItem(obst10a);
    path10a.moveTo(obst10a->boundingRect().width(),obst10a->boundingRect().height()/2);
    path10a.arcTo(obst10a->boundingRect(), 0, 55);
    obst10a->customPath = path10a;

    // Obsticle 10 path b created
    obst10b = new Obsticles_Inside_Scene();
    obst10b->setPos(330,-2200 );
    obst10b->itempen.setColor(Qt::yellow);
    scene->addItem(obst10b);
    path10b.moveTo(0,obst10b->boundingRect().height()/2);
    path10b.arcTo(obst10b->boundingRect(),180, 55);
    obst10b->customPath = path10b;


    //Obsticle Point score adder if sucessfully crossed
    increaseScore10 = new scoringitem();
    increaseScore10->setPos(370,-2445 );
    scene->addItem(increaseScore10);


    /***************CONNECTING SIGNALS AND SLOTS*****************************/
    timer = new QTimer(this);
    QObject::connect(timer,SIGNAL(timeout()),scene ,SLOT(advance()));
    QObject::connect(timer,SIGNAL(timeout()),scene ,SLOT(update()));
    //QObject::connect(ball,SIGNAL(countScore()),playerScore,SLOT(count()));


    QObject::connect(user,SIGNAL(spacePressed()),ball,SLOT(spacePressed_Slot()));
    QObject::connect(user,SIGNAL(spaceReleased()),ball,SLOT(spaceReleased_Slot()));
    QObject::connect(user,SIGNAL(clickPressed()),ball,SLOT(spacePressed_Slot()));
    QObject::connect(user,SIGNAL(clickReleased()),ball,SLOT(spaceReleased_Slot()));




    /***************CONNECTING  Obsticle 1 with its Slots*****************************/
    QObject::connect(user,SIGNAL(spacePressed()),obst1a,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(spaceReleased()),obst1a,SLOT(spaceReleased_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickPressed()),obst1a,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickReleased()),obst1a,SLOT(spaceReleased_ObsticleSlot()));

    QObject::connect(user,SIGNAL(spacePressed()),obst1b,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(spaceReleased()),obst1b,SLOT(spaceReleased_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickPressed()),obst1b,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickReleased()),obst1b,SLOT(spaceReleased_ObsticleSlot()));

    QObject::connect(user,SIGNAL(spacePressed()),increaseScore1,SLOT(spacePressed_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(spaceReleased()),increaseScore1,SLOT(spaceReleased_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(clickPressed()),increaseScore1,SLOT(spacePressed_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(clickReleased()),increaseScore1,SLOT(spaceReleased_Increase_Score_Slot()));





    /***************CONNECTING  Obsticle 2 with its Slots*****************************/

    QObject::connect(user,SIGNAL(spacePressed()),obst2a,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(spaceReleased()),obst2a,SLOT(spaceReleased_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickPressed()),obst2a,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickReleased()),obst2a,SLOT(spaceReleased_ObsticleSlot()));

    QObject::connect(user,SIGNAL(spacePressed()),obst2b,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(spaceReleased()),obst2b,SLOT(spaceReleased_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickPressed()),obst2b,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickReleased()),obst2b,SLOT(spaceReleased_ObsticleSlot()));

    QObject::connect(user,SIGNAL(spacePressed()),increaseScore2,SLOT(spacePressed_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(spaceReleased()),increaseScore2,SLOT(spaceReleased_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(clickPressed()),increaseScore2,SLOT(spacePressed_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(clickReleased()),increaseScore2,SLOT(spaceReleased_Increase_Score_Slot()));


    /***************CONNECTING  Obsticle 3 with its Slots*****************************/

    QObject::connect(user,SIGNAL(spacePressed()),obst3a,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(spaceReleased()),obst3a,SLOT(spaceReleased_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickPressed()),obst3a,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickReleased()),obst3a,SLOT(spaceReleased_ObsticleSlot()));

    QObject::connect(user,SIGNAL(spacePressed()),obst3b,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(spaceReleased()),obst3b,SLOT(spaceReleased_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickPressed()),obst3b,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickReleased()),obst3b,SLOT(spaceReleased_ObsticleSlot()));

    QObject::connect(user,SIGNAL(spacePressed()),increaseScore3,SLOT(spacePressed_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(spaceReleased()),increaseScore3,SLOT(spaceReleased_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(clickPressed()),increaseScore3,SLOT(spacePressed_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(clickReleased()),increaseScore3,SLOT(spaceReleased_Increase_Score_Slot()));



    /***************CONNECTING  Obsticle 4 with its Slots*****************************/


    QObject::connect(user,SIGNAL(spacePressed()),obst4a,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(spaceReleased()),obst4a,SLOT(spaceReleased_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickPressed()),obst4a,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickReleased()),obst4a,SLOT(spaceReleased_ObsticleSlot()));

    QObject::connect(user,SIGNAL(spacePressed()),obst4b,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(spaceReleased()),obst4b,SLOT(spaceReleased_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickPressed()),obst4b,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickReleased()),obst4b,SLOT(spaceReleased_ObsticleSlot()));

    QObject::connect(user,SIGNAL(spacePressed()),increaseScore4,SLOT(spacePressed_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(spaceReleased()),increaseScore4,SLOT(spaceReleased_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(clickPressed()),increaseScore4,SLOT(spacePressed_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(clickReleased()),increaseScore4,SLOT(spaceReleased_Increase_Score_Slot()));


    /***************CONNECTING  Obsticle 5 with its Slots*****************************/

    QObject::connect(user,SIGNAL(spacePressed()),obst5a,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(spaceReleased()),obst5a,SLOT(spaceReleased_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickPressed()),obst5a,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickReleased()),obst5a,SLOT(spaceReleased_ObsticleSlot()));

    QObject::connect(user,SIGNAL(spacePressed()),obst5b,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(spaceReleased()),obst5b,SLOT(spaceReleased_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickPressed()),obst5b,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickReleased()),obst5b,SLOT(spaceReleased_ObsticleSlot()));

    QObject::connect(user,SIGNAL(spacePressed()),increaseScore5,SLOT(spacePressed_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(spaceReleased()),increaseScore5,SLOT(spaceReleased_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(clickPressed()),increaseScore5,SLOT(spacePressed_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(clickReleased()),increaseScore5,SLOT(spaceReleased_Increase_Score_Slot()));





    /***************CONNECTING  Obsticle 6 with its Slots*****************************/

    QObject::connect(user,SIGNAL(spacePressed()),obst6a,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(spaceReleased()),obst6a,SLOT(spaceReleased_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickPressed()),obst6a,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickReleased()),obst6a,SLOT(spaceReleased_ObsticleSlot()));

    QObject::connect(user,SIGNAL(spacePressed()),obst6b,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(spaceReleased()),obst6b,SLOT(spaceReleased_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickPressed()),obst6b,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickReleased()),obst6b,SLOT(spaceReleased_ObsticleSlot()));

    QObject::connect(user,SIGNAL(spacePressed()),increaseScore6,SLOT(spacePressed_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(spaceReleased()),increaseScore6,SLOT(spaceReleased_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(clickPressed()),increaseScore6,SLOT(spacePressed_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(clickReleased()),increaseScore6,SLOT(spaceReleased_Increase_Score_Slot()));



    /***************CONNECTING  Obsticle 7 with its Slots*****************************/

    QObject::connect(user,SIGNAL(spacePressed()),obst7a,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(spaceReleased()),obst7a,SLOT(spaceReleased_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickPressed()),obst7a,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickReleased()),obst7a,SLOT(spaceReleased_ObsticleSlot()));

    QObject::connect(user,SIGNAL(spacePressed()),obst7b,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(spaceReleased()),obst7b,SLOT(spaceReleased_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickPressed()),obst7b,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickReleased()),obst7b,SLOT(spaceReleased_ObsticleSlot()));

    QObject::connect(user,SIGNAL(spacePressed()),increaseScore7,SLOT(spacePressed_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(spaceReleased()),increaseScore7,SLOT(spaceReleased_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(clickPressed()),increaseScore7,SLOT(spacePressed_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(clickReleased()),increaseScore7,SLOT(spaceReleased_Increase_Score_Slot()));





    /***************CONNECTING  Obsticle 8 with its Slots*****************************/

    QObject::connect(user,SIGNAL(spacePressed()),obst8a,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(spaceReleased()),obst8a,SLOT(spaceReleased_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickPressed()),obst8a,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickReleased()),obst8a,SLOT(spaceReleased_ObsticleSlot()));

    QObject::connect(user,SIGNAL(spacePressed()),obst8b,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(spaceReleased()),obst8b,SLOT(spaceReleased_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickPressed()),obst8b,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickReleased()),obst8b,SLOT(spaceReleased_ObsticleSlot()));

    QObject::connect(user,SIGNAL(spacePressed()),increaseScore8,SLOT(spacePressed_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(spaceReleased()),increaseScore8,SLOT(spaceReleased_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(clickPressed()),increaseScore8,SLOT(spacePressed_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(clickReleased()),increaseScore8,SLOT(spaceReleased_Increase_Score_Slot()));


    /***************CONNECTING  Obsticle 9 with its Slots*****************************/

    QObject::connect(user,SIGNAL(spacePressed()),obst9a,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(spaceReleased()),obst9a,SLOT(spaceReleased_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickPressed()),obst9a,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickReleased()),obst9a,SLOT(spaceReleased_ObsticleSlot()));

    QObject::connect(user,SIGNAL(spacePressed()),obst9b,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(spaceReleased()),obst9b,SLOT(spaceReleased_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickPressed()),obst9b,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickReleased()),obst9b,SLOT(spaceReleased_ObsticleSlot()));

    QObject::connect(user,SIGNAL(spacePressed()),increaseScore9,SLOT(spacePressed_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(spaceReleased()),increaseScore9,SLOT(spaceReleased_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(clickPressed()),increaseScore9,SLOT(spacePressed_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(clickReleased()),increaseScore9,SLOT(spaceReleased_Increase_Score_Slot()));





    /***************CONNECTING  Obsticle 10 with its Slots*****************************/

    QObject::connect(user,SIGNAL(spacePressed()),obst10a,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(spaceReleased()),obst10a,SLOT(spaceReleased_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickPressed()),obst10a,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickReleased()),obst10a,SLOT(spaceReleased_ObsticleSlot()));

    QObject::connect(user,SIGNAL(spacePressed()),obst10b,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(spaceReleased()),obst10b,SLOT(spaceReleased_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickPressed()),obst10b,SLOT(spacePressed_ObsticleSlot()));
    QObject::connect(user,SIGNAL(clickReleased()),obst10b,SLOT(spaceReleased_ObsticleSlot()));

    QObject::connect(user,SIGNAL(spacePressed()),increaseScore10,SLOT(spacePressed_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(spaceReleased()),increaseScore10,SLOT(spaceReleased_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(clickPressed()),increaseScore10,SLOT(spacePressed_Increase_Score_Slot()));
    QObject::connect(user,SIGNAL(clickReleased()),increaseScore10,SLOT(spaceReleased_Increase_Score_Slot()));



    timer->start(25);


}




GameMainWindow::~GameMainWindow()
{
    delete ui;
}





void GameMainWindow::gameOver()
{
    if( ball->pos().y() + ball->rec.height() < 0  || ball->pos().y()  > 600 + ball->rec.height() )
    {

        QString message;
        message = "Game is Over";
        diplayGameWindow(message);

    }

}




//void GameMainWindow::start()
//{

//}





void GameMainWindow::diplayGameWindow(QString dispText)
{


    for(size_t i = 0, n = scene->items().size(); i < n; i++)
    {
        scene->items()[i]->setEnabled(false);

    }

    QGraphicsTextItem *text = new QGraphicsTextItem(dispText) ;
    text->setPos(400,200);
    scene->addItem(text);
}





void GameMainWindow::playgame()
{
    //layout1->addWidget(view);
    //win->setLayout(layout1);
    delete Playgame_button;
    //setCentralWidget(view);
    view->show();
    this->close();


}




