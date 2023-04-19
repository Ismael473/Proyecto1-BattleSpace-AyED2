#ifndef LISTAENEMY_H
#define LISTAENEMY_H

#include <iostream>
#include "Enemy.h"

using namespace std;

/*!
 * \brief The Nodo class
 */
class Nodo{
public:
    Enemy* data;
    Nodo* next;

};

/*!
 * \brief The ListaEnemy class
 */
class ListaEnemy{
public:
    Nodo* first;


    ListaEnemy(){
        first = nullptr;
    }
    void agregar(Enemy* enemy){

        Nodo* newNode = new Nodo;
        newNode->data = enemy;
        newNode->next = first;
        first = newNode;


    }

    void eliminar(){
        first = first->next;

    }


};

#endif


