#include <enemy.h>
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <bullet.h>
#include <game.h>
#include <QDebug>
#include <QMessageBox>
#include <Button.h>
extern Game * game;

Enemy::Enemy(QList<QPointF> pointsToFollow, QGraphicsItem *parent){
    // tạo ảnh cho enemy
    setPixmap(QPixmap("E:/MediaQt/Tower/Enemy1.png"));
    
    // Moi Enemy co 100 mau
    health = 100;
    // Khởi tạo giá trị các điểm
    points = pointsToFollow;
    point_index = 0;
    dest = points[0];
    rotateToPoint(dest); // Điểm rẽ

    // Kết nối với Timer vì Enemy cần di chuyển .
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveForward()));
    timer->start(60);

}

void Enemy::rotateToPoint(QPointF p){

    QLineF ln(pos(),p);
    setRotation(-1 * ln.angle());

}

void Enemy::setHealth(int n)
{
    health = n;

}

int Enemy::getHealth()
{
    return health;
}

void Enemy::moveForward(){
    if (pos().x() == 0){ // Cổng phòng thủ năm ở vị trí Bìa phải của gốc tọa độ

               // Máu của người chơi giảm xuống
               game->health->decrease();
               scene()->removeItem(this);

               delete this;
               return;
    }

    QList<QGraphicsItem *> colliding_items = collidingItems();

        // nếu danh sách đụng độ có 1 bullet thì máu của Enemy giảm đi 50 và Bullet biến mất
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Bullet)){


                health -= 50;
                scene()->removeItem(colliding_items[i]); // Bullet biến mất

                if(health == 0){ // Máu Enemy bằng 0
                    game->score->increase(); // Tiêu diệt 1 Enemy , Score ++

                    if(game->score->getScore()>=50){ // Score = 50 thì chiến thắng

                        game->spawnTimer->disconnect();  // Ngắt Timer
                        for(int i=0;i<game->scene->items().size();i++){
                            game->scene->items()[i]->setEnabled(false);  // Vô hiệu hóa các Item trên Scene
                        }
                        game->drawPanel(250,190,300,230,Qt::lightGray,0.75); // Bảng Thông báo

                        Button* close = new Button (QString(" You Win !!!"));
                        close->setPos(game->scene->width()/2-100,game->scene->height()/2-25);
                        game->scene->addItem(close);
                        connect(close,SIGNAL(clicked()),this,SLOT(close()));
                    }
                    scene()->removeItem(colliding_items[i]); // Bullet Biến Mất
                    scene()->removeItem(this); // Enemy biến mất
                    // clear Bộ Nhớ Heap
                    delete colliding_items[i];
                    delete this;
                }

                // return
                return;
            }
        }
    // Nếu Không bị đạn bắn
    // Di chuyên đến điểm đích đã định sẵn
    QLineF ln(pos(),dest);
    if (ln.length() < 5){
        point_index++;
        // Điểm cuối đã đi tới
        if (point_index >= points.size()){
            return;
        }
        // Điểm cuối chưa đi tới
        dest = points[point_index];
        rotateToPoint(dest); // Cho Enemy Rẽ
    }
    // Enemy di chuyển theo 1 hướng , mỗi 1 phần thời gian là 5 đơn vị
    int STEP_SIZE = 5;
    double theta = rotation(); // đưa về degrees
    // tính khoảng cách vị trí mới , góc để rẽ
    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy); // đặt vị trí mới lên màn hình

}
