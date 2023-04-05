#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>

Enemy::Enemy()
{
    int random_number = (rand() % 550);
    qDebug()<< random_number;
    setPos (750, random_number);
    setRect(0,0,100,100);
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this,SLOT(move()));

    timer->start(50);

}
void Enemy::move(){
    setPos(x()-5,y());
    if (pos().x() > 800){
        scene()->removeItem(this);
        qDebug() << "Eliminada";
        delete this;
    }
}
