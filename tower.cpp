#include <tower.h>
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <bullet.h>
#include <QPointF>
#include <QLineF>
#include <game.h>
#include <QTimer>
#include <QGraphicsRectItem>
#include <enemy.h>

extern Game * game;

#include <QDebug>

Tower::Tower(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent){

    // các điểm tạo thành 1 Polygon
    QVector<QPointF> points;
    points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2) << QPoint(2,3)
               << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);

    // tỉ lệ của 1 polygon
    int SCALE_FACTOR = 75;

    for (size_t i = 0, n = points.size(); i < n; i++){
        points[i] *= SCALE_FACTOR;
    }

    // Tạo Polygon
    attack_area = new QGraphicsPolygonItem(QPolygonF(points),this);
    attack_area->setPen(QPen(Qt::DotLine));


    QPointF poly_center(1.5,1.5); // Sau khi tính toán , ta được tâm của Polygon
    poly_center *= SCALE_FACTOR; // tỉ lệ điểm
    poly_center = mapToScene(poly_center); // Tích hợp với tọa độ của QGraphicsScene được Khái bảo ở Lớp Game
    QPointF tower_center(x()+30,y()+30); // điểm trung tâm của trụ
    QLineF ln(poly_center,tower_center); // đường thẳng tử tâm của Polygon đến tâm của trụ
    attack_area->setPos(x()+ln.dx(),y()+ln.dy()); // tính toán điểm bắn


   // khởi đầu = false
    has_target = false;
}

double Tower::distanceTo(QGraphicsItem *item){
    // returns the distance to the item
    QLineF ln(this->pos(),item->pos());
    return ln.length();
}

void Tower::fire(){

    Bullet * bullet = new Bullet();
    bullet->setPos(x()+44,y()+44);

    QLineF ln(QPointF(x()+44,y()+44),attack_dest);
    int angle = -1 * ln.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

void Tower::aquire_target(){
    // tạo một danh sách đụng độ giữa Polygon và các đối tượng khác.
    // đặt attack_dest ngay sau khi đụng độ
    // danh sach doi tuong dung do voi Polygon da tao cho Tru qua ham CollidingItems()
    QList<QGraphicsItem *> colliding_items = attack_area->collidingItems();
    // khong tim thay dung do , ko co muc tieu
    has_target = false;
    // tim mot doi tuong Enemy gan nhat , o day la 400 ban kinh polygon
    double closest_dist = 400;
    QPointF closest_pt(0,0);
    for (size_t i = 0, n = colliding_items.size(); i < n; ++i){

        // loc cac doi tuong khac , chac chan no la doi tuong Enemy
        Enemy * enemy = dynamic_cast<Enemy *>(colliding_items[i]);

        // xu ly neu dung do
        if (enemy){
            double this_dist = distanceTo(colliding_items[i]);
            if (this_dist < closest_dist){
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;

            }
        }
    }
    // neu co muc tieu , set diem ban , goi ham fire ( ban ).
    if (has_target){
        attack_dest = closest_pt;
        fire();
    }
}
