#include<iostream>
#include"client.h"
#include"LinkedList.h"
#include"casher.h"
#include"Queue.h"
#include"Bank.h"


using namespace std;



int main()
{
    ///inpust
    int intrruptCount=0;
    int client_number,casher_number,current_client_number=0,
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
            intrruptCount=0;
        if(current_client_number<client_number)
            {
            cout<<"Please Enter info  of Client["<<current_client_number+1<<"]"<<endl;
            cout<<"Enter Arrival Time"<<endl;
            cin>>arrival;
            cout<<"Enter Service Time"<<endl;
            cin>>service;


            clientArr[current_client_number].setArrival(arrival);
            clientArr[current_client_number].setService(service);
            clientArr[current_client_number].setID(current_client_number+1);

            cout<<"Do you have any interruption for this client enter 1 or not 0"<<endl;
            cin>>chooseAnyInteruption;
        if(chooseAnyInteruption==1)  ///if you want to enter another interruption press 1 otherwise press 0
        {
            intrruptCount++;
            while(chooseInteruption==1){
                cout<<"Please Enter Value of interruption_time"<<endl;
                cin>>interruption_time;
                interruption_time_list.Add(interruption_time);

                cout<<"If you enter another interruption for this client please enter 1 not 0"<<endl;
                cin>>chooseInteruption;
            }

            clientArr[current_client_number].setInteruption(interruption_time_list);

             ///assign list of interruption to client
        }
            if(intrruptCount >=1)
                clientArr[current_client_number].setInteruptionFlag(true);

                current_client_number++;
            cout<<"Do you want Enter client again 1 or not enter 0"<<endl;
            cin>>chooseAnotherClient;

        }else
            {
                cout<<"Not Valid number"<<endl;break;
            }
	}


cout<<"-----------------------"<<endl;
 Bank bank = Bank(0,current_client_number,casher_number);
/// client sortedClientArr[current_client_number]=bank.sortClientArr(clientArr,current_client_number);
bank.sortClientArr(clientArr,current_client_number);
for(int i=0;i<current_client_number;i++){
    cout<<clientArr[i].getArrival()<<endl;
}
cout<<"-----------------------"<<endl;
///bank.servingClient(clientArr,casherArr,current_client_number ,casher_number);
bank.displayReport(clientArr,current_client_number);
	return 0;
}













