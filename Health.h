#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem{
public:
    Health(QGraphicsItem * parent=0);
    void reducir();
    int getHealth();
private:
    int health;
    int enemyHealth;
};

#endif // HEALTH_H
