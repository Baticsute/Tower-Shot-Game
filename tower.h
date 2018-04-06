#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

class Tower:public QObject, public QGraphicsPixmapItem{ // Là lớp kiểu QGraphicsPixmapItem , QObject để chạy timer
    Q_OBJECT
public:

    Tower(QGraphicsItem * parent=0); // Hàm khởi tạo
    double distanceTo(QGraphicsItem * item); // khoảng cách đến đối tượng khác
    virtual void fire(); // phương thức trừu tượng , phát ra đạn khi có mục tiêu

public slots:

    void aquire_target(); // slot được định nghĩa phát hiện mục tiêu

protected:

    QGraphicsPolygonItem * attack_area; // là polygon bao quanh trụ , xác định vùng bắn khi có kẻ thù
    QPointF attack_dest; // là điểm cần bắn vào mục tiêu
    bool has_target; // biến binary xác định có/không mục tiêu

};

#endif // TOWER_H
