#ifndef BUILDLEVEL1TOWERICON_H
#define BUILDLEVEL1TOWERICON_H


#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildLevel1TowerIcon: public QGraphicsPixmapItem{

public:
   BuildLevel1TowerIcon(QGraphicsItem* parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    int cost;
};

#endif // BUILDLEVEL1TOWERICON_H
