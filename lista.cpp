#include <iostream>
#include <conio.h>
#include "Enemy.h"
#include <QObject>
#include <QGraphicsPixmapItem>


using namespace std;

class Node: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy data;
    Node* next = NULL;
};
class List: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
    Node* head;
public:
    List(){
        head = NULL;
    }
    void insertlist(Enemy * d){
        Node* n = new Node();
        n->data = d;
        n->next = NULL;
        if (head == NULL){
            head = n;
        }
        else{
            Node* temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
                temp->next = n;
            }
        }
    }
    void trasverselist()
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
