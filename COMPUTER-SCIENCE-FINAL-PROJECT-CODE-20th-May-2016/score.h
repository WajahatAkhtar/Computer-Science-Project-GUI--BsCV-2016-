#ifndef SCORE_H
#define SCORE_H

/********************* HEADER FILES***************************/

#include <QGraphicsTextItem>
#include <QFont>



class Score : public QGraphicsTextItem
{
public:
    //Public Member Variables

    //Constructors and Destructors
    Score();
    ~Score(){}

    //Member Functions
    int getScore()const;
    void count();


private:

    int score;

};

#endif // SCORE_H





