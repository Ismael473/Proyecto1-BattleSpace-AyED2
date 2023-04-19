#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

/*!
 * \brief The Health class
 */
class Health: public QGraphicsTextItem{
public:
    // Constructor
    Health(QGraphicsItem * parent=0);
    // Metodos
    void reducir();
    int getHealth();
private:
    int health;
    int enemyHealth;
};

#endif // HEALTH_H
