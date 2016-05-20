#ifndef OBSTICLES_INSIDE_SCENE_H
#define OBSTICLES_INSIDE_SCENE_H


/********************* HEADER FILES***************************/

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>
#include <QPaintEvent>





class Obsticles_Inside_Scene:public QObject, public QGraphicsItem
{

    Q_OBJECT            // In order to handle signal and slot we add a macro / Q_OBJECT

public:
    //Member variables
    QPen  itemPen1 ;
    QPen itempen;
    QPen itemPen3;
    QPen itemPen4;
    QPainterPath customPath;
    QRectF rec;
    qreal object_speed_obst;

    //Constructor or Destructor
    Obsticles_Inside_Scene();
    ~Obsticles_Inside_Scene(){}

    //Memeber Functions
    QRectF boundingRect()const;
    QPainterPath shape()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    //void paintEvent(QPaintEvent *event);
    //void draw(QPainter *painter);

public slots:
    void rotateObj();
    void advance(int phase);
    void spacePressed_ObsticleSlot();
    void spaceReleased_ObsticleSlot();



};

#endif // OBSTICLES_INSIDE_SCENE_H
