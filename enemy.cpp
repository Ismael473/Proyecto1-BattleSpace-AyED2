#include "Enemy.h"
#include <QTimer>
#include <QDebug>
#include <stdlib.h>
#include "Game.h"
#include <QGraphicsPixmapItem>

extern Game * game;

Enemy::Enemy(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent)
{
    //Creando la imagen.
    setPixmap(QPixmap(":/images/enemy.png"));
    setScale(0.25);


    int random_number = (rand() % 550);
    setPos (750, random_number);
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this,SLOT(move()));

    timer->start(50);

}
void Enemy::move(){

    setPos(x()-5,y());
    if (pos().x() < 0){
        game->health->reducir();
        scene()->removeItem(this);
        delete this;

    }
}
