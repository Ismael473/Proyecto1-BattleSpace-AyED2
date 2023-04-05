#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

Bullet::Bullet()
{
    setRect(0,0,50,10);
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this,SLOT(move()));

    timer->start(50);

}
void Bullet::move(){
    setPos(x()+10,y());
    if (pos().x() > 800){
        scene()->removeItem(this);
        qDebug() << "Eliminada";
        delete this;
    }
}
