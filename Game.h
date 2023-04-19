#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Wave.h"
#include "Health.h"
#include "Enemy.h"
#include "Bullet.h"

/*!
 * \brief The Game class
 */
class Game: public QGraphicsView{
    Q_OBJECT
public:
    // Constructor
    Game(QWidget * parent=NULL);

    //Metodos
    void mainMenu();

    // Argumentos
    QGraphicsScene *scene;
    Player * player;
    Wave * wave;
    Health * health;
    Enemy * enemy;
    Bullet * bullet;

public slots:
    void easy();
    void medium();
    void hard();
};

#endif // GAME_H
