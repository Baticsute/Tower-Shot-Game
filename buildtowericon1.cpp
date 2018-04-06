#include "buildtowericon1.h"
#include <QPixmap>
#include <game.h>

extern Game * game;
BuildTowerIcon1::BuildTowerIcon1(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap("E:/MediaQt/Tower/PNG/Retina/towerDefense_tile089.png"));
}

void BuildTowerIcon1::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->build){
        game->build = new Tower();
        game->setCursor(QString("E:/MediaQt/bricklvl1.png"));
    }
}
