#include <iostream>
#include "Game.h"
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <Button.h>
#include <QTimer>
#include "ListaEnemy.h"

using namespace std;

/*!
 * \brief Game::Game
 * \param parent
 */
Game::Game(QWidget *parent){

    scene = new QGraphicsScene(); // Se crea la escena donde se mostrar el juego
    scene->setSceneRect(0,0,800,600); // Se le asignan valores al ancho y largo de la escena
    setBackgroundBrush(QBrush(QImage(":/images/bg.jpg"))); // Se agrega el fondo del juego

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //Se bloquean las barras horizontales y verticales
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Esto para la escena no siga creciendo
    setFixedSize(800, 600); // Se fija el ancho y largo de la pantalla


}

/*!
 * \brief Game::easy, crea la dificultad facil del juego
 * \param no recibe parametros
 * \return no retorna valores
 */
void Game::easy(){

    scene->clear(); // Se limpia la pantall

    player = new Player(); // Se crea una instancia de la clase jugador
    player->setPos(0, 250);//Se usa para tener siempre al jugador centrado.
    player->setFlag(QGraphicsItem::ItemIsFocusable); // Con esto hacemos que el jugador se pueda mover
    player->setFocus();

    scene->addItem(player); // Se agrega el jugador a la escena

    wave = new Wave(); // Se crea el contador de oleadas
    scene->addItem(wave);

    health = new Health(); // Se crea la vida del jugador
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);

    player->spawnEasy(); // Con esto spawnean los enemigos de la dificultad facil


}

/*!
 * \brief Game::medium, se crea la dificultad media del juego.
 * \param no recibe parametros
 * \return no retorna nada
 */
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
/*!
 * \brief Game::hard, se crea la dificultad dificil del juego
 * \param no recibe parametros
 * \return no retorna nada
 */
void Game::hard(){
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

    player->spawnHard();
}
/*!
 * \brief Game::mainMenu, es la pantalla de inicio del juego
 * \param no recibe parametros
 * \return no retorna nada
 */
void Game::mainMenu()
{
    // Se crea el titulo del juego y se le da tamano y color
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
    connect(easyButton,SIGNAL(clicked()),this,SLOT(easy()));// Esto hace que cuando se presione el boton realice una accion
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




