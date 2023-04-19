#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>

/*!
 * \brief The Enemy class
 */
class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    // Constructor
    Enemy();

    // Argumentos
    QGraphicsPixmapItem * enemyPixmap;
    QPixmap ePix;

    // Metodos
    int vida;
    int getVida();
    void setVida(int nvida);
    void reducir();

public slots:
    void move();



};


#endif // ENEMY_H
