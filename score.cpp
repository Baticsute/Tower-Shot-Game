#include <score.h>
#include <QFont>
#include<QMessageBox>
Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){

    score = 3;


    setPos(680,550);
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}

void Score::increase(){
    score++;
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
}

void Score::decrease(int n)
{
    score -= n;
    if(score >= 0){
     setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
    }else{
        setPlainText(QString("Score: 0"));
    }

}

int Score::getScore(){
    return score;
}
