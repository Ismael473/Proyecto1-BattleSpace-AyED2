#include "Health.h"
#include <QFont>

/*!
 * \brief Health::Health
 * \param parent
 * \return no retorna nada
 */
Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    health = 3;
    enemyHealth = 5;

    setPlainText("Health: " + QString::number(health));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times", 16));

}
/*!
 * \brief Health::reducir reduce la vida del jugador
 * \param no recibe valores
 * \return no retorna nada
 */
void Health::reducir(){
    health--;
    setPlainText("Health: " + QString::number(health));
}
/*!
 * \brief Health::getHealth
 * \return retorna la vida del jugador
 */
int Health::getHealth(){
    return health;
}
