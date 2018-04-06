#include <buildlevel2towericon.h>
#include <game.h>
#include <level2tower.h>

extern Game * game;

BuildLevel2TowerIcon::BuildLevel2TowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    cost = 2;
    setPixmap(QPixmap("E:/MediaQt/Tower/level2.png"));
}

void BuildLevel2TowerIcon::mousePressEvent(QGraphicsSceneMouseEvent* event){

    if (!game->building){
        game->building = new Level2Tower();
        game->score->decrease(cost);
        game->setCursor(QString("E:/MediaQt/Tower/tower2.png"));
    }

}
