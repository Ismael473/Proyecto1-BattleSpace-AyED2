#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"
#include "ListaEnemy.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <iostream>
#include <QTime>
#include <QCoreApplication>
#include <QEventLoop>
#include <QGraphicsTextItem>

extern Game * game;
using namespace std;
ListaEnemy wave;

/*!
 * \brief Player::Player
 * \param parent
 * \return no retorna nada
 */
Player::Player(QGraphicsItem * parent): QGraphicsPixmapItem(parent){

    setPixmap(QPixmap(":/images/Player.png")); // se le da una imagen al jugador
    setScale(0.3);


}
/*!
 * \brief Player::keyPressEvent
 * \param event, recibe un evento(una tecla presionada)
 * \return no retorna nada
 */
void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up){
        if (pos().y()>0){
            setPos(x(),y()-10);
        }
    }
    else if (event->key() == Qt::Key_Down){
        if (pos().y()+100 < 600){
            setPos(x(), y()+10);
        }
    }
    else if (event->key()== Qt::Key_Space){
        Bullet * bullet = new Bullet(); // crea una bala y la muestra en pantalla
        bullet->setPos(x()+120,y()+67);
        scene()->addItem(bullet);

    }

}
/*!
 * \brief Player::delay, agrega un retraso en la aparicion de oleadas
 * \param no recibe parametros
 * \return no retorna nada
 */
void Player::delay(){

    QTime dieTime = QTime::currentTime().addSecs(7);
    while(QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}

/*!
 * \brief Player::spawnEasy, spawnea los enemigos de la dificultad facil
 * \param no recibe parametros
 * \return no retorna nada
 */
void Player::spawnEasy(){
    ListaEnemy wave;
    int i;
    for(i = 0; i < 1; i++){
        Enemy * enemy = new Enemy(); // crea al enemigo y lo muestra en pantalla
        wave.agregar(enemy);
        scene()->addItem(enemy);
    }

    game->wave->aumentar();// aumenta el contador de oleadas
    this->delay();
    for(i = 0; i < 2; i++){
        Enemy * enemy = new Enemy();
        wave.agregar(enemy);
        scene()->addItem(enemy);
    }
    game->wave->aumentar();
    this->delay();
    for(i = 0; i < 3; i++){
        Enemy * enemy = new Enemy();
        wave.agregar(enemy);
        scene()->addItem(enemy);
    }
    game->wave->aumentar();
    this->delay();
    for(i = 0; i < 4; i++){
        Enemy * enemy = new Enemy();
        wave.agregar(enemy);
        scene()->addItem(enemy);
    }
    game->wave->aumentar();
    this->delay();
    for(i = 0; i < 5; i++){
        Enemy * enemy = new Enemy();
        wave.agregar(enemy);
        scene()->addItem(enemy);
    }

}
/*!
 * \brief Player::spawnMedium, crea los enemigos de la dificultad media
 * \param no recibe parametros
 * \return no retorna nada
 */
void Player::spawnMedium(){
    ListaEnemy wave;

    int i;
    for(i = 0; i < 2; i ++){
        Enemy * enemy = new Enemy();
        wave.agregar(enemy);
        scene()->addItem(enemy);
    }
    game->wave->aumentar();
    this->delay();
    for(i = 0; i < 3; i ++){
        Enemy * enemy = new Enemy();
        wave.agregar(enemy);
        scene()->addItem(enemy);
    }
    game->wave->aumentar();
    this->delay();
    for(i = 0; i < 4; i ++){
        Enemy * enemy = new Enemy();
        wave.agregar(enemy);
        scene()->addItem(enemy);
    }
    game->wave->aumentar();
    this->delay();
    for(i = 0; i < 5; i ++){
        Enemy * enemy = new Enemy();
        wave.agregar(enemy);
        scene()->addItem(enemy);
    }
    game->wave->aumentar();
    this->delay();
    for(i = 0; i < 5; i ++){
        Enemy * enemy = new Enemy();
        wave.agregar(enemy);
        scene()->addItem(enemy);
    }
    this->delay();
}
/*!
 * \brief Player::spawnHard, crea los enemigos de la dificultad dificil
 * \param no recibe parametros
 * \return no retorna nada
 */
void Player::spawnHard(){
    ListaEnemy wave;
    int i;
    for(i = 0; i < 3; i ++){
        Enemy * enemy = new Enemy();
        wave.agregar(enemy);
        scene()->addItem(enemy);
    }
    game->wave->aumentar();
    this->delay();
    for(i = 0; i < 3; i ++){
        Enemy * enemy = new Enemy();
        wave.agregar(enemy);
        scene()->addItem(enemy);
    }
    game->wave->aumentar();
    this->delay();
    for(i = 0; i < 4; i ++){
        Enemy * enemy = new Enemy();
        wave.agregar(enemy);
        scene()->addItem(enemy);
    }
    game->wave->aumentar();
    this->delay();
    for(i = 0; i < 6; i ++){
        Enemy * enemy = new Enemy();
        wave.agregar(enemy);
        scene()->addItem(enemy);
    }
    game->wave->aumentar();
    this->delay();
    for(i = 0; i < 6; i ++){
        Enemy * enemy = new Enemy();
        wave.agregar(enemy);
        scene()->addItem(enemy);
    }
    this->delay();

}
