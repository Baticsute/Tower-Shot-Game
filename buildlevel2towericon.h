#ifndef BUILDLEVEL2TOWERICON_H
#define BUILDLEVEL2TOWERICON_H


#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildLevel2TowerIcon: public QGraphicsPixmapItem{

public:

   BuildLevel2TowerIcon(QGraphicsItem* parent=0);
   void mousePressEvent(QGraphicsSceneMouseEvent* event);
   int cost;
};
#endif // BUILDLEVEL2TOWERICON_H
