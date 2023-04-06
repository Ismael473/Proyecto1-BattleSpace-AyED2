#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"


class Game: public QGraphicsView{
public:
    Game(QWidget * parent=00);

    QGraphicsScene *scene;
    Player * player;
    Score * score;
    Health * health;


};

#endif // GAME_H