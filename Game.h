#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Wave.h"
#include "Health.h"


class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget * parent=NULL);

    //Metodos
    void mainMenu();

    QGraphicsScene *scene;
    Player * player;
    Wave * wave;
    Health * health;

public slots:
    void easy();
    void medium();
    void hard();
};

#endif // GAME_H
