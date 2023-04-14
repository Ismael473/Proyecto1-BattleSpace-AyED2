#include "Enemy.h"
#include <QTimer>
#include <QDebug>
#include <stdlib.h>
#include "Game.h"
#include <QGraphicsPixmapItem>
#include <iostream>
#include "ListaEnemy.cpp"


extern Game * game;

Enemy::Enemy(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent)
{
    //Creando la imagen.
    setPixmap(QPixmap(":/images/enemy.png"));
    setScale(0.25);

    vida = 5;

    int random_number = (rand() % 550);
    setPos (750, random_number);

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this,SLOT(move()));
    timer->start(50);


}

int Enemy::getVida(){
    return vida;
}
void Enemy::reducir(){
    vida--;
}
void Enemy::setVida(int nvida){
    vida = nvida;
}

void Enemy::move(){

    setPos(x()-5,y());
    if (pos().x() < 0){
        game->health->reducir();
        scene()->removeItem(this);
        delete this;

    }
}

