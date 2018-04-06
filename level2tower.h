#ifndef LEVEL2TOWER_H
#define LEVEL2TOWER_H


#include <tower.h>

class Level2Tower: public Tower{
    Q_OBJECT
public:
    Level2Tower(QGraphicsItem * parent=0);
    void fire();
public slots:
    void aquire_target();
};

#endif // LEVEL2TOWER_H
