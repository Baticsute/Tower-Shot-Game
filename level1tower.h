#ifndef LEVEL1TOWER_H
#define LEVEL1TOWER_H


#include <tower.h>

class Level1Tower: public Tower{
    Q_OBJECT
public:
    Level1Tower(QGraphicsItem * parent=0);
    void fire();
public slots:
    void aquire_target();
};

#endif // LEVEL1TOWER_H
