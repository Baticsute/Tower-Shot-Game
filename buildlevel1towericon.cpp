#include <buildlevel1towericon.h>
#include <game.h>
#include <level1tower.h>
#include <QDebug>

extern Game * game;

BuildLevel1TowerIcon::BuildLevel1TowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    cost = 1;
    setPixmap(QPixmap("E:/MediaQt/Tower/level1.png"));
}

void BuildLevel1TowerIcon::mousePressEvent(QGraphicsSceneMouseEvent* event){

    if (!game->building){
            game->building = new Level1Tower();
            game->score->decrease(cost);
            //qDebug() << game->score->getScore();
            game->setCursor(QString("E:/MediaQt/Tower/tower1.png"));

    }

}
