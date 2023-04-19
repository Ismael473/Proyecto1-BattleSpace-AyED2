#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "ListaEnemy.h"


/*!
 * \brief The Player class
 */
class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    // Constructor
    Player(QGraphicsItem * parent=0);
    // Argumentos
    ListaEnemy wave;
    // Metodos
    void keyPressEvent(QKeyEvent * event);
    void delay();
public slots:
    void spawnEasy();
    void spawnMedium();
    void spawnHard();
};

#endif // PLAYER_H
