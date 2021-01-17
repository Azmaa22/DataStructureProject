Queue<client> assignCasherToClient(client arr1[],casher arr2[],int len1,int len2){

    Queue<client> clientWaitting;

    for(int i=0;i<len2;i++){
        if(arr2[i].getSrvingFlag()==0)
            {
               arr2[i].setServingFlag(1);
               arr1[i].setNumberOfCasher(i);

            }
            }

   for(int i=0;i<len1;i++){

    clientWaitting.Enqueu(arr1[i]);
   }

return clientWaitting;
}

///------------------------------------------------------------
Queue<client> emptyQueue(Queue<client> Q){
   while(Q.IsEmpty()){
    Q.Dequeue();
   }
return Q;
}
///------------------------------------------------------------

/*void calcWaittingTime(clientArr,casherArr,current_client_number,casher_number){
Queue <client> Q;
Queue <client> QClone;
Queue <client> QC;

Q=assignCasherToClient(clientArr,casherArr,current_client_number,casher_number);

int iCasher,currentCasher;
iCasher=0;
client currentClient;
LinkedList InterruptionList;
Node *currentInterruptionTime;
int currentServingTime;
int newServingTime;

    while(iCasher<casher_number){
        currentClient=Q.FrontValue();
        Q.Dequeue();
        ///calculate Around  time
        currentCasher=currentClient.getNumberOFCasher();
       if(currentClient.getHasInterruption()){///if true
          casherArr[currentCasher].setServingFlag(false);
          InterruptionList = currentClient.getInterruption();
          currentInterruptionTime = InterruptionList.head;
          if(currentInterruptionTime->Next!=NULL){
             ///equation
          currentServingTime = casherArr[currentCasher].getserving_time();
          newServingTime=currentServingTime+currentInterruptionTime->Data;
          casherArr[currentCasher].setserving_time(newServingTime);
          currentClient.setAroundTime(currentInterruptionTime->Data);
          currentClient.setNumberOFCasher(-1);
          Q.Enqueu(currentClient);
          currentInterruptionTime=currentInterruptionTime->Next;

          }else {cout<<"Finish Interruption"<<endl;}


       }
       else {/// if false
         ///equation
        currentClient.setAroundTime(currentClient.getService());
        casherArr[currentCasher].setserving_time(currentClient.getService());
        casherArr[currentCasher].setServingFlag(false);
        currentClient.setNumberOfCasher(-1);
            }
    }
    QC = Q;
///when number of casher finish
     while(QC.IsEmpty()){

       for(int i=0;i<QC.getLength();i++){
           QClone.Enqueu(Q.FrontValue().setWaittingTime()) ;
           Q.Dequeue();
                        }
        Q=QClone;
        QClone=emptyQueue(QClone);
     }

}

*/

