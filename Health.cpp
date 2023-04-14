#include "Health.h"
#include <QFont>


Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    health = 3;
    enemyHealth = 5;

    setPlainText("Health: " + QString::number(health));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times", 16));

}

void Health::reducir(){
    health--;
    setPlainText("Health: " + QString::number(health));
}

int Health::getHealth(){
    return health;
}
