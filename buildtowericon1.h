#ifndef BUILDTOWERICON1_H
#define BUILDTOWERICON1_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildTowerIcon1: public QGraphicsPixmapItem
{
public:
    BuildTowerIcon1(QGraphicsItem * parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // BUILDTOWERICON1_H
