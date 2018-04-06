#include <health.h>
#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){

    health = 10;


    setPos(680,570);
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 100
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // Health: --
}

int Health::getHealth(){
    return health;
}
