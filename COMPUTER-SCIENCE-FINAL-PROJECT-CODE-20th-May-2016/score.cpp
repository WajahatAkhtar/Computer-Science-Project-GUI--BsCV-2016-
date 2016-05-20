#include "score.h"




Score::Score(){
    score = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));


}



int Score::getScore() const
{
    return score;
}



void Score::count()
{
    score++;
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1

}


