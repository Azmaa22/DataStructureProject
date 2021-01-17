#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include<iostream>
using namespace std;

template<class T>
class LinkedList
{
    public: Node<T> *head, *tail;

public:
    LinkedList()
    {
        head = tail = NULL;
    }


    void Add(T data)
    {
        Node<T> *newNode = new Node<T>(data);

        if(head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->Next = newNode;
            newNode->Prev = tail;
            tail = newNode;
        }
    }

    void deleteFirst(){

     Node<T> *current ;
         current=head;
        if(current->Next!=NULL)
        {
            head=current->Next;
        }
        else{
            head=NULL;
        }

    }

    void Display()
    {
        Node<T> *current = head;

        while(current != NULL)
        {
            cout << (current->Data) << endl;
            current = current->Next;
        }
    }







private:
    Node<T>* Search(T *data)
    {
        Node<T> *current = head;

        while(current != NULL)
        {
            if(current->Data == data)
                return current;

            current = current->Next;
        }

        return NULL;
    }


};

#endif // LINKEDLIST_H
