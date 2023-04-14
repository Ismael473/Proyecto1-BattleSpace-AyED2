#include <iostream>
#include "Enemy.h"

using namespace std;


class Nodo{
public:
    Enemy* data;
    Nodo* next;

};

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


};
