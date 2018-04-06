#include <buildlevel3towericon.h>
#include <game.h>
#include <level3tower.h>

extern Game * game;

BuildLevel3TowerIcon::BuildLevel3TowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    cost = 3;
    setPixmap(QPixmap("E:/MediaQt/Tower/level33.png"));
}

void BuildLevel3TowerIcon::mousePressEvent(QGraphicsSceneMouseEvent* event){

    if (!game->building){
        game->building = new Level3Tower();
        game->score->decrease(cost);
        game->setCursor(QString("E:/MediaQt/Tower/tower3.png"));
    }

}
