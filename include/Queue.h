#ifndef QUEUELIST_H
#define QUEUELIST_H

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


    private:
};

#endif // QUEUELIST_H
