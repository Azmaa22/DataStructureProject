#ifndef BANK_H
#define BANK_H
#include"casher.h"
#include"client.h"
#include"Queue.h"
#include"LinkedList.h"
#include"Node.h"

class Bank
{
      private:
        int system_counter,
        indexCuerrentClient,
        client_number,casher_number   ;

    public:
        Bank() {
            indexCuerrentClient=0;
            system_counter=0;}

             Bank(int system_time,int c1,int c2){
                indexCuerrentClient=0;
                system_counter=system_time;
                client_number=c1;
                casher_number=c2;
                }


    void setSystemCounter(int val){system_counter=val;}
    int getSystemCounter(){return system_counter;}
    ///Report function
    void displayReport(client clientArr[],int number_client){
          cout<<"-----------------------------------------------------------------"<<endl;
          cout<<"clientID | ArrivalTime | ExpectedTime | AroundTime | WaitingTime ";
          cout<<"-----------------------------------------------------------------"<<endl;
    for(int i=0;i<number_client;i++){
          clientArr[i].setWaittingTime(clientArr[i].getAroundTime()- clientArr[i].getService());

           cout<<    clientArr[i].getID()   <<"|"<<clientArr[i].getArrival()<<"|"<<clientArr[i].getService()<<"|"<<clientArr[i].getAroundTime()<<"|"<<clientArr[i].getWaittingTime()<<endl;

    }
     cout<<"The System Time is : "<<endl;
    }
    ///sort clientArr according to arrival time of ever client
    void sortClientArr(client clientArr[],int number_client){

       client clientTemp;
       for(int i=0;i<number_client;i++){
        for(int j=0;j<=number_client-1-i;j++){
            if(clientArr[i].getArrival() > clientArr[j].getArrival()){
                 clientTemp=clientArr[i];
                 clientArr[i]=clientArr[j];
                 clientArr[j]=clientTemp;
            }
        }
       }

    }

    ///function to dequeue from waiting queue the clients that it will service
    Queue<client> removeServiceClients(Queue<client> WQ,int number_casher){

        for(int i=0;i<number_casher;i++){
            WQ.Dequeue();
        }
    return WQ;
    }

    ///function to assign client to casher
Queue<client> assignCasherToClient(client clientArr[],casher casherArr[], int start_service){

       Queue<client> clientWaitting=assignClientInWaiting( clientArr);
       Queue<client> servecingClient;  ///to start serving
       client currentClient;

            for(int i=0;i<casher_number;i++){
                if(casherArr[i].getSrvingFlag()==0)
                    {
                        currentClient=clientWaitting.FrontValue();
                        clientWaitting.Dequeue();
                        casherArr[i].setServingFlag(1);///if chaser empty not work assign client to it
                        currentClient.setNumberOfCasher(i);
                        currentClient.setstart_service_time(start_service);
                        servecingClient.Enqueu(currentClient);

                    }
            }

return servecingClient;
}


 ///function to assign client in waiting queue
Queue<client> assignClientInWaiting(client clientArr[]){
     Queue<client> clientWaitting;

       for(int i=0;i<client_number;i++){
           clientWaitting.Enqueu(clientArr[i]);
      }
return clientWaitting;
}

///function to start service of client and if have interruption stop servicing and go to waiting queue
void servingClient(client clientArr[],casher casherArr[],int client_number,int casher_num){
Queue<client> waitingQueue;
Queue<client> servingQueue;
 ///all clients
 waitingQueue=assignClientInWaiting(clientArr);

   int currentCasher;
    client currentClient;

    LinkedList <int> InterruptionList;
    Node <int> *currentInterruptionTime;
    int time;

    while(waitingQueue.IsEmpty()!=0  ){
            ///every casher hold a client
        servingQueue=assignCasherToClient(clientArr,casherArr,system_counter);
        ///delete Clients in servingQueue  from waiting Clients
        waitingQueue=removeServiceClients(waitingQueue,casher_num);
       ///start serving

        while(servingQueue.IsEmpty()!=0){
            currentClient = servingQueue.FrontValue();
            if(currentClient.getstart_service_time() == system_counter){

                if(currentClient.getHasInterruption()== true ){
             ///has interruption
               InterruptionList=currentClient.getInterruption();
               currentInterruptionTime=InterruptionList.head;

                if(currentInterruptionTime!= NULL){
                time = currentInterruptionTime->Data;
                int tempTime=time+currentClient.getstart_service_time();
                if(tempTime== system_counter){

                         InterruptionList.deleteFirst();/// remove head

                         currentClient.setInteruption(InterruptionList);///new interruption List
                         waitingQueue.Enqueu(currentClient);///return to waiting queue
                         servingQueue.Dequeue();

                         break;
                }
                time--; ///to calculate remain time of serving
                currentInterruptionTime->Data=time;
                InterruptionList.head->Data=currentInterruptionTime->Data;
                currentClient.setInteruption(InterruptionList);
                servingQueue.Dequeue();
                servingQueue.Enqueu(currentClient);

               }

            }
            else {
                ///no interruption
                currentClient.setAroundTime(system_counter);
                servingQueue.Dequeue();


            }

            }

        }
        system_counter++;

    }

}




};

#endif // BANK_H
