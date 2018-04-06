#include <level2tower.h>
#include <QTimer>
#include <bullet.h>
#include <game.h>
#include <QPixmap>

extern Game * game;

Level2Tower::Level2Tower(QGraphicsItem *parent){


    // connect a timer to aquire_target
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(100);


}

void Level2Tower::fire(){




    Bullet * bullet = new Bullet();
    Bullet * bullet1 = new Bullet();
    QPixmap p("E:/MediaQt/Tower/BulletLevel2.png");
    p=p.scaled(64,20);


    bullet->setPixmap(p);
    bullet1->setPixmap(p);

    bullet->setPos(x()+30,y()+30);
    bullet1->setPos(x()+30,y()+30);


    QLineF ln(QPointF(x()+30,y()+30),attack_dest);

    //QGraphicsPixmapItem * p = new QGraphicsPixmapItem();


    int angle = -1 * ln.angle();

    //p->setRotation(angle);
    bullet->setRotation(angle);
    bullet1->setRotation(angle+10);

   // game->scene->addItem(p);
    game->scene->addItem(bullet);
    game->scene->addItem(bullet1);

}

void Level2Tower::aquire_target(){
    Tower::aquire_target();
}
