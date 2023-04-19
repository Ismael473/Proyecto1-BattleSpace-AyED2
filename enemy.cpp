#include "Enemy.h"
#include "Game.h"
#include <QTimer>
#include <QDebug>
#include <stdlib.h>
#include <QGraphicsPixmapItem>
#include <iostream>



extern Game * game;

Enemy::Enemy()
{
    //Creando la imagen.

    QPixmap ePix(":/images/enemy.png");
    enemyPixmap = new QGraphicsPixmapItem(ePix);
    setPixmap(ePix);
    setScale(0.25);

    vida = 5;

    // Esto se encarga de que la posicion en el eje y siempre sea aleatoria
    int random_number = (rand() % 550);
    setPos (750, random_number);

    // Se usa un Qtimer para llamar constantemente a la funcion move()
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this,SLOT(move()));
    timer->start(50);


}

/*!
 * \brief Enemy::getVida
 * \param no recibe parametros
 * \return retorna la vida de la nave
 */
int Enemy::getVida(){
    return vida;
}
/*!
 * \brief Enemy::reducir reduce la vida de la nave enemiga
 * \param no recibe parametros
 * \return no retorna nada
 */
void Enemy::reducir(){
    vida--;
}
/*!
 * \brief Enemy::setVida, cambia la vida de la nave enemiga
 * \param nvida, la vida nueva que tendra la nave enemiga
 * \return no retorna nada
 */
void Enemy::setVida(int nvida){
    vida = nvida;
}

/*!
 * \brief Enemy::move mueve la nave enemiga
 * \param no recibe parametros
 * \return no retorna nada
 */
void Enemy::move(){
    setPos(x()-5,y());
    if (pos().x() < 0){ // Cuando la nave supere el 0 de la pantalla se elimina y se resta una vida al jugador
        game->health->reducir();
        scene()->removeItem(this);
        delete this;

    }
}

