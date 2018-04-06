#include <level3tower.h>
#include <QTimer>
#include <bullet.h>
#include <game.h>
#include <QPixmap>
#include <QGraphicsPixmapItem>

extern Game * game;

Level3Tower::Level3Tower(QGraphicsItem *parent){

    // connect a timer to aquire_target
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(300);

}

void Level3Tower::fire(){

    Bullet * bullet1 = new Bullet();
    Bullet * bullet2 = new Bullet();
    Bullet * bullet3 = new Bullet();


    QPixmap p("E:/MediaQt/Tower/Level3.png");
    p=p.scaled(64,20);

    bullet1->setPixmap(p);
    bullet2->setPixmap(p);
    bullet3->setPixmap(p);


    bullet1->setPos(x()+30,y()+30);
    bullet2->setPos(x()+30,y()+30);
    bullet3->setPos(x()+30,y()+30);


    QLineF ln(QPointF(x()+30,y()+30),attack_dest);
    int angle = -1 * ln.angle();

    bullet1->setRotation(angle);
    bullet2->setRotation(angle+10);
    bullet3->setRotation(angle-10);

    game->scene->addItem(bullet1);
    game->scene->addItem(bullet2);
    game->scene->addItem(bullet3);

}

void Level3Tower::aquire_target(){
    Tower::aquire_target();
}
