#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

Bullet::Bullet()
{
    setPixmap(QPixmap(":/images/bullet.png"));
    setScale(0.05);



    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this,SLOT(move()));

    timer->start(50);

}
void Bullet::move(){
    setPos(x()+10,y());
    if (pos().x() > 800){
        scene()->removeItem(this);
        delete this;
    }
}
