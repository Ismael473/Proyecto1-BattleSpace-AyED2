#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"
#include "ListaEnemy.cpp"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <iostream>
#include <QTime>
#include <QCoreApplication>
#include <QEventLoop>
#include <QGraphicsTextItem>

extern Game * game;
using namespace std;

Player::Player(QGraphicsItem * parent): QGraphicsPixmapItem(parent){

    setPixmap(QPixmap(":/images/Player.png"));
    //scaled(100,100, Qt::KeepAspectRatio, Qt::FastTransformation);
    setScale(0.3);


}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up){
        if (pos().y()>0){
            setPos(x(),y()-10);
        }
    }
    else if (event->key() == Qt::Key_Down){
        if (pos().y()+100 < 600){
            setPos(x(), y()+10);
        }
    }
    else if (event->key()== Qt::Key_Space){
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+120,y()+67);
        scene()->addItem(bullet);
    }

}
void Player::delay(){

    QTime dieTime = QTime::currentTime().addSecs(7);
    while(QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}

void Player::spawnEasy(){
    ListaEnemy wave1;
    ListaEnemy wave2;
    ListaEnemy wave3;
    ListaEnemy wave4;
    ListaEnemy wave5;
    int i;
    for(i = 0; i < 1; i++){
        Enemy * enemy = new Enemy();
        wave1.agregar(enemy);
        scene()->addItem(enemy);
    }
    game->wave->aumentar();
    this->delay();
    for(i = 0; i < 2; i++){
        Enemy * enemy = new Enemy();
        wave2.agregar(enemy);
        scene()->addItem(enemy);
    }
    game->wave->aumentar();
    this->delay();
    for(i = 0; i < 3; i++){
        Enemy * enemy = new Enemy();
        wave3.agregar(enemy);
        scene()->addItem(enemy);
    }
    game->wave->aumentar();
    this->delay();
    for(i = 0; i < 4; i++){
        Enemy * enemy = new Enemy();
        wave4.agregar(enemy);
        scene()->addItem(enemy);
    }
    game->wave->aumentar();
    this->delay();
    for(i = 0; i < 5; i++){
        Enemy * enemy = new Enemy();
        wave5.agregar(enemy);
        scene()->addItem(enemy);
    }
    /*
    Nodo* actual = list.first;
    while(actual != nullptr){
        cout << actual->data << endl;
        actual = actual->next;
    }*/
}
void Player::spawnMedium(){
    ListaEnemy wave1;
    ListaEnemy wave2;
    ListaEnemy wave3;
    ListaEnemy wave4;
    ListaEnemy wave5;
    int i;
    for(i = 0; i < 2; i ++){
        Enemy * enemy = new Enemy();
        wave1.agregar(enemy);
        scene()->addItem(enemy);
    }
    this->delay();
    for(i = 0; i < 3; i ++){
        Enemy * enemy = new Enemy();
        wave2.agregar(enemy);
        scene()->addItem(enemy);
    }
    this->delay();
    for(i = 0; i < 4; i ++){
        Enemy * enemy = new Enemy();
        wave3.agregar(enemy);
        scene()->addItem(enemy);
    }
    this->delay();
    for(i = 0; i < 5; i ++){
        Enemy * enemy = new Enemy();
        wave4.agregar(enemy);
        scene()->addItem(enemy);
    }
    this->delay();
    for(i = 0; i < 5; i ++){
        Enemy * enemy = new Enemy();
        wave5.agregar(enemy);
        scene()->addItem(enemy);
    }
    this->delay();
}
