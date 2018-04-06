#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList> // list << element
#include <QPointF>

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QList<QPointF> pointsToFollow, QGraphicsItem * parent=0);
    void rotateToPoint(QPointF p); // Enemy rẽ theo hướng chỉ định
    void setHealth(int n); // đặt máu cho Enemy
    int getHealth();
public slots:
    void moveForward(); // hàm di chuyển về từng điểm
private:
    QList<QPointF> points; // Danh sách điểm cần di chuyển
    QPointF dest; // điểm đích trong danh sách
    int point_index; // chỉ số của điểm cần di chuyển
    int health; // máu của Enemy

};

#endif // ENEMY_H
