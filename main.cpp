#include <QApplication>
#include "MyRect.h"
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include "list.hpp"
#include <QTimer>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    QGraphicsScene * scene = new QGraphicsScene();

    MyRect * player = new MyRect();
    player->setRect(0,0,100,100);

    scene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //Se crea la escena
    QGraphicsView * view = new QGraphicsView(scene);

    //Con esto se bloquean las srollbars, esto para que la escena no siga creciendo.
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    view->setFixedSize(800, 600);
    scene->setSceneRect(0,0,800,600);

    player->setPos(0, view->height()/2-50);

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    

    return a.exec();
}
