#ifndef BUILDLEVEL3TOWEICON_H
#define BUILDLEVEL3TOWEICON_H


#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildLevel3TowerIcon: public QGraphicsPixmapItem{

public:

   BuildLevel3TowerIcon(QGraphicsItem* parent=0);
   void mousePressEvent(QGraphicsSceneMouseEvent* event);

};
#endif // BUILDLEVEL3TOWEICON_H
