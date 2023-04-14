#include <iostream>
#include "Game.h"
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <Button.h>
#include <QTimer>
#include "ListaEnemy.cpp"

using namespace std;

Game::Game(QWidget *parent){

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/bg.jpg")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);


}


void Game::easy(){

    scene->clear();

    player = new Player();
    player->setPos(0, 250);//Se usa para tener siempre al jugador centrado.
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);

    wave = new Wave();
    scene->addItem(wave);

    health = new Health();
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);

    player->spawnEasy();

    //QTimer * timer = new QTimer();
    //QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawnEasy()));
    //timer->start(2000);
}


void Game::medium(){

    scene->clear();

    player = new Player();
    player->setPos(0, 250);//Se usa para tener siempre al jugador centrado.
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);

    wave = new Wave();
    scene->addItem(wave);

    health = new Health();
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);

    player->spawnMedium();

}
void Game::hard(){
    cout << "Hola" << endl;
}

void Game::mainMenu()
{
    QGraphicsTextItem * titleText = new QGraphicsTextItem(QString("BattleSpace"));
    QFont titleFont("comic sans", 50);
    titleText->setDefaultTextColor(Qt::red);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos, tyPos);
    scene->addItem(titleText);


   //Creando los botones
    Button * easyButton =new Button(QString("Facil"));
    int exPos = this->width()/2 - easyButton->boundingRect().width()/2;
    int eyPos = 275;
    easyButton->setPos(exPos, eyPos);
    connect(easyButton,SIGNAL(clicked()),this,SLOT(easy()));
    scene->addItem(easyButton);

    Button * mediumButton = new Button(QString("Media"));
    int mxPos = this->width()/2 - mediumButton->boundingRect().width()/2;
    int myPos = 350;
    mediumButton->setPos(mxPos, myPos);
    connect(mediumButton,SIGNAL(clicked()),this,SLOT(medium()));
    scene->addItem(mediumButton);

    Button * hardButton = new Button(QString("Dificil"));
    int hxPos = this->width()/2 - hardButton->boundingRect().width()/2;
    int hyPos = 425;
    hardButton->setPos(hxPos, hyPos);
    connect(hardButton,SIGNAL(clicked()),this,SLOT(hard()));
    scene->addItem(hardButton);

    Button * quit = new Button(QString("Salir"));
    int sxPos = this->width()/2 - quit->boundingRect().width()/2;
    int syPos = 500;
    quit->setPos(sxPos, syPos);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quit);
}




