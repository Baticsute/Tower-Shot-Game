#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include <tower.h>
#include <score.h>
#include <health.h>


class Game: public QGraphicsView{
    Q_OBJECT
public:

    Game();
    void setCursor(QString filename); // Tạo con trỏ ảo , click chuột để mua Tower , đặt Tower vào ụ
    void mouseMoveEvent(QMouseEvent *event); // Sự kiện di chuyển chuột
    void mousePressEvent(QMouseEvent *event); // sự kiên click chuột
    void createEnemies(int numberOfEnemies); //Tạo Ra một loạt Enemy
    void creatRoad(); // Phương thức này không dùng đến.
    void drawPanel(int x,int y, int width,int height, QColor color,double opacity); // Bảng thông báo Win/Game Over

    QGraphicsScene * scene; // Phối cảnh giữ GraphicsView
    QGraphicsPixmapItem * cursor; // Con trỏ chuột là một PixmapItem
    Tower * building; // Là một đối tượng Trụ được đặt tại vị trí cần xây
    QTimer * spawnTimer; // Timer tạo ra các đối tượng
    int enemiesSpawned; // số Enemy được tạo
    int maxNumberOfEnemies; // Max Enemy
    QList<QPointF> pointsToFollow; // Điểm cần di chuyển của enemy , được đinh sẵn trên Khung Nhìn Oxy

    Score * score; // Điểm của người chơi

    Health * health; // Máu của người chơi

public slots:
    void spawnEnemy(); // Phương thức truyền Tạo Enemy
};

#endif // GAME_H
