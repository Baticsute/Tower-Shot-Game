#include <level1tower.h>
#include <QTimer>
#include <bullet.h>
#include <game.h>
#include <QGraphicsPixmapItem>

extern Game * game;
Level1Tower::Level1Tower(QGraphicsItem *parent){

    // Kết nối Timer khi phát hiện mục tiêu
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(300);

}
void Level1Tower::fire(){

    Bullet * bullet = new Bullet();
    QPixmap p("E:/MediaQt/Tower/BulletLevel1.png"); // hình cho viên đạn
    p=p.scaled(64,20); // nén lại tỉ lệ

    bullet->setPixmap(p); //đặt hình
    bullet->setPos(x()+30,y()+30); // đạn xuất phát từ
    bullet->setMaxRange(100); // đặt độ dài đường đi tối đa là 100
    QLineF ln(QPointF(x()+30,y()+30),attack_dest); // đường thẳng vẻ từ mục tiêu đến tâm của polygon
    int angle = -1 * ln.angle(); // đương đi của viên đạn
    bullet->setRotation(angle); // transform viên đạn
    game->scene->addItem(bullet); // thêm viên đạn vào cảnh
}
void Level1Tower::aquire_target(){ // Phương thức thừa kế từ lớp cha Tower
    Tower::aquire_target();
}
