#include <bullet.h>
#include <QPixmap>
#include <QTimer>
#include <qmath.h> // qSin, qCos, qTan
#include <game.h>
#include <enemy.h>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <qmath.h>
extern Game * game;

Bullet::Bullet(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){

    // Kết nối Timer
    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(70);

    //Khởi tạo các giá trị
    maxRange = 100;
    distanceTravelled = 0;

}

void Bullet::move(){


    // TÍNH TOÁN ĐƯỜNG ĐI CHO ĐƯỜNG ĐẠN BẰNG CÔNG THỨC :

    int STEP_SIZE = 30;
    double theta = rotation(); // degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);

    distanceTravelled+=10;

}

double Bullet::getMaxRange(){
    return maxRange;
}

double Bullet::getDistanceTravelled(){
    return distanceTravelled;
}

void Bullet::setMaxRange(double rng){
maxRange = rng;
}

void Bullet::setDistanceTravelled(double dist){
    distanceTravelled = dist;
}
