#include<iostream>
#include"client.h"
#include"LinkedList.h"
#include"casher.h"
#include"Queue.h"

#include"system.h"

using namespace std;



int main()
{
    ///inpust
    int client_number,casher_number,i=0,
    arrival,service,chooseAnotherClient=1,
    chooseAnyInteruption, numClient,interruption_time,chooseInteruption=1;
    LinkedList <int>interruption_time_list;

	cout<<"Please Enter number of Clients"<<endl;
	cin>>client_number;

    cout<<"Please Enter number of Casher"<<endl;
	cin>>casher_number;

	client clientArr[client_number];
	casher casherArr[casher_number];

	while(chooseAnotherClient==1){ ///if you want to enter another client press 1 otherwise press 0
        if(i<client_number)
            {
            cout<<"Please Enter info  of Client["<<i+1<<"]"<<endl;
            cout<<"Enter Arrival Time"<<endl;
            cin>>arrival;
            cout<<"Enter Service Time"<<endl;
            cin>>service;

            clientArr[i].setArrival(arrival);
            clientArr[i].setService(service);

            cout<<"Do you have any interruption for this client enter 1 or not 0"<<endl;
            cin>>chooseAnyInteruption;
        if(chooseAnyInteruption==1)  ///if you want to enter another interruption press 1 otherwise press 0
        {
            while(chooseInteruption==1){
                cout<<"Please Enter Value of interruption_time"<<endl;
                cin>>interruption_time;
                interruption_time_list.Add(interruption_time);
                cout<<"If you enter another interruption for this client please enter 1 not 0"<<endl;
                cin>>chooseInteruption;
            }
            clientArr[i].setInteruption(interruption_time_list);  ///assign list of interruption to client
        }

                i++;
            cout<<"Do you want Enter client again 1 or not enter 0"<<endl;
            cin>>chooseAnotherClient;

        }else
            {
                cout<<"Not Valid number"<<endl;break;
            }

        }




      for(int j=0;j<i;j++){
        cout<<clientArr[j].getArrival()<<endl;
        cout<<clientArr[j].getService()<<endl;

        clientArr[j].getInterruption().Display();
       }


       cout<<"QQQQQQQQQQQQQQQQQ"<<endl;
       Queue<client> q =  assignCasherToClient(clientArr,casherArr,i,casher_number);
        while(q.IsEmpty()){
            cout<<q.FrontValue().getNumberOFCasher()<<" : "<<q.FrontValue().getArrival()<<endl;
            q.Dequeue();
        }

	return 0;
}













