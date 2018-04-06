#include <Button.h>
#include <QBrush>
#include <QGraphicsTextItem>
#include <QFont>
Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);

     cc = new QGraphicsTextItem(name,this);
     int xPos = rect().width()/2- cc->boundingRect().width()/2;
     int yPos = rect().height()/2-cc->boundingRect().height()/2;
     cc->setPos(xPos,yPos);
     cc->setFont(QFont("times",10));
     setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
}
