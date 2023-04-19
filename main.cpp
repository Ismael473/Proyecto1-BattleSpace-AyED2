#include <QApplication>
#include "Game.h"


Game* game; // Se crea la instancia de la clase juego

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show(); // Muestra en pantalla el juego
    game->mainMenu(); // Muestra como primera pantalla el menu principal

    

    return a.exec();
}
