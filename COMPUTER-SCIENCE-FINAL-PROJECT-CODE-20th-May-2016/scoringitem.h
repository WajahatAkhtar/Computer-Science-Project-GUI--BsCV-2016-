#ifndef ADDSCORE_H
#define ADDSCORE_H

/********************* HEADER FILES***************************/

#include <QGraphicsPixmapItem>
#include <QObject>



class scoringitem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT        // QObject is used whenever we are using signals and slots

public:
    // Construtor
    scoringitem();
    // Destructor
    ~scoringitem(){}

    //Public Member Variables
    qreal point_increase_obst;

    //SLOTS
public slots:

    void advance(int phase);
    void spacePressed_Increase_Score_Slot();
    void spaceReleased_Increase_Score_Slot();
};

#endif // ADDSCORE_H
