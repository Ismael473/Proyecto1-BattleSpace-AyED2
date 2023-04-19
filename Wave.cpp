#include "Wave.h"
#include <QFont>

/*!
 * \brief Wave::Wave, crea el contador de oleadas
 * \param parent
 * \return no retorna nada
 */
Wave::Wave(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    wave = 0;

    setPlainText("Oleada: " + QString::number(wave));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times", 16));

}
/*!
 * \brief Wave::aumentar, aumenta el contador de oleadas
 * \param no recibe parametros
 * \return no retorna nada
 */
void Wave::aumentar(){
    wave++;
    setPlainText("Oleada: " + QString::number(wave));
}
/*!
 * \brief Wave::getWave
 * \param no recibe parametros
 * \return, retorna la oleada actual
 */
int Wave::getWave(){
    return wave;
}
