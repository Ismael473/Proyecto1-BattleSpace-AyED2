#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "Enemy.h"

/*!
 * \brief The Bullet class
 */
class Bullet: public QObject, public QGraphicsPixmapItem{
    //Con este macro nos aseguramos de que la clase Bullet sea un objeto manipulable, esto para poder hacer
    // uso de los QTimers
    Q_OBJECT
public:
    // Constructor
    Bullet();
    //Argumentos
    QGraphicsPixmapItem * bulletPixmap;
    QPixmap bPix;
    QGraphicsPixmapItem * rect;
    // Metodos
    void detection(QGraphicsPixmapItem* other);
public slots:
    void move();



};


#endif // BULLET_H
