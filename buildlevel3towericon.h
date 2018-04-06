#ifndef BUILDLEVEL3TOWERICON_H
#define BUILDLEVEL3TOWERICON_H


#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildLevel3TowerIcon: public QGraphicsPixmapItem{

public:

   BuildLevel3TowerIcon(QGraphicsItem* parent=0);
   void mousePressEvent(QGraphicsSceneMouseEvent* event);
   int cost;
};

#endif // BUILDLEVEL3TOWERICON_H
