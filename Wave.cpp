#include "Wave.h"
#include <QFont>


Wave::Wave(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    wave = 0;

    setPlainText("Oleada: " + QString::number(wave));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times", 16));

}

void Wave::aumentar(){
    wave++;
    setPlainText("Oleada: " + QString::number(wave));
}

int Wave::getWave(){
    return wave;
}
