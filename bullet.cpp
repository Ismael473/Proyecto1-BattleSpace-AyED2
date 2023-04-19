#include "Bullet.h"
#include "enemy.cpp"
#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <iostream>
#include <QList>
#include <QGraphicsPixmapItem>


extern Game * game;
using namespace std;

/*!
 * \brief Bullet::Bullet
 * \param no recibe parametros
 */
Bullet::Bullet()
{
    QPixmap bPix(":/images/bullet.png"); // Se crea un objeto Pixmap con la imagen de la bala.
    bulletPixmap = new QGraphicsPixmapItem(bPix); // Se crea un objeto PixmapItem, esto para poder detec
    setPixmap(bPix); // Se agrega la imagen.
    setScale(0.05); // Con esto se escala la imagen.


    //El QTimer se utiliza para llamar continuamente a la funcion move() la cual se encarga de mover la bala
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this,SLOT(move()));
    timer->start(50);

}
/*!
 * \brief Bullet::move, la funcion move se encarga de mover la bala hacia la derecha.
 * \param no recibe parametros
 * \return no retorna nada
 */
void Bullet::move(){
    /*
    if(bulletPixmap->collidesWithItem(game->enemy)){
        scene()->removeItem(this);
        return;
    }
    */
    //Este if se asegura de eliminar la bala una vez que salga de pantalla
    setPos(x()+10,y());
    if (pos().x() > 800){
        scene()->removeItem(this);
        delete this;
    }

}

/*!
 * \brief Bullet::detection
 * \param other, un puntero a un objeto QGraphisPixmapItem
 * \return no retorna nada
 */
void Bullet::detection(QGraphicsPixmapItem* other){
    // Esta funcion se planeaba utilizar para detectar colisiones
    if (this->collidesWithItem(other)){
        scene()->removeItem(this);
        return;
    }
}

