#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent=0);
    int getVida();
    void setVida(int nvida);
    void reducir();
public slots:
    void move();
private:
    int vida;

};


#endif // ENEMY_H
