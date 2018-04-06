#ifndef LEVEL3TOWER_H
#define LEVEL3TOWER_H


#include <tower.h>

class Level3Tower: public Tower{
    Q_OBJECT
public:
    Level3Tower(QGraphicsItem * parent=0);
    void fire();
public slots:
    void aquire_target();
};

#endif // LEVEL3TOWER_H
