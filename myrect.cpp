#include "MyRect.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Bullet.h"
#include "Enemy.h"


void MyRect::keyPressEvent(QKeyEvent *event)
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
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
    }

}

void MyRect::spawn(){
    //Linkedlist list;
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
    //list.insertNode(enemy);

}
