#include "Player.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Bullet.h"
#include "Enemy.h"
#include <QGraphicsPixmapItem>
//#include "lista.cpp"

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

void Player::spawn(){
    //List l;
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
    //l.insertlist(enemy);

}
