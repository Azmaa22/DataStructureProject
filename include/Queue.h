#ifndef QUEUELIST_H
#define QUEUELIST_H
#include"LinkedList.h"
#include "Node.h"
using namespace std;
template <class T>
class Queue
{
    public:
        Node<T> *head,*tail;int length;

        Queue() {

        head=tail=NULL;
        length=0;
        }

        void Enqueu(T data){
            Node<T> *newNode=new Node<T>(data);

          if(head==NULL){
            head=tail=newNode;
            }
            else{
                tail->Next=newNode;
                newNode->Prev=tail;
                tail=newNode;
            }

            length++;
        }
///////////////////
        void Dequeue(){
            Node <T> * current;
            current=head->Next;
            delete head;
            head=current;
            --length;
           }

       ////////////
void DeleteByIndex(int index)
    {
       Node<T> *pDelete = Searchindex(index);

        if(pDelete == NULL)
            return;

        if(pDelete == head)
        {
            if(pDelete == tail) // if(head->Next == NULL)
            {
                head = tail = NULL;
            }
            else
            {
                head = head->Next;
                head->Prev = NULL;
            }
        }
        else if(pDelete == tail)
        {

            tail = tail->Prev;
            tail->Next = NULL;
        }
        else
        {
            pDelete->Prev->Next = pDelete->Next; // A->Next = B
            pDelete->Next->Prev = pDelete->Prev; // B->Prev = A
        }

        delete pDelete;

    }


        int IsEmpty(){
          if(length){
            return length;
          }
          else{
            return 0;
          }

       }

       T FrontValue(){
         return head->Data;
       }

       void displayList(){

         Node <T> *current;
          current=head;
          while(current!=NULL){
                //current->Data
            cout<<current->Data<<endl;
            current=current->Next;
          }


        }
       int getLength(){return length;}

    private:
        int index;
         Node<T>* Searchindex(int x)
         {
              Node<T> *current = head;
              index=0;
             while(current != NULL)
            {
                  if(index == x)
                      return current;

                 current = current->Next;
                   index++;
            }

            return NULL;
         }
};

#endif // QUEUELIST_H
