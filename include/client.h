#ifndef CLIENT_H
#define CLIENT_H

#include "LinkedList.h"
#include"casher.h"
class client
{
    public:

        void setArrival(int t){arrival_time=t;}
        void setService(int t){service_time=t;}
        void setNumberOfCasher(int num){numberOfCasher=num;}
        void setWaittingTime(){
            waitting_time++;}
        void setInteruption(LinkedList<int> L){
             interuption_time=L;

            }
        void setFinishingFlag(bool f){finishing=f;}
        void setInteruptionFlag(bool f){hasInterruption=f;}
        void setAroundTime(int t){around_time=t;}
        client(int t1,int t2){
          arrival_time=t1;
          service_time=t2;
          final_time=0;
          waitting_time=0;
          finishing=false;
          numberOfCasher=-1;
           hasInterruption=false;
           around_time=0;
        }
        client(){
            around_time=0;
         arrival_time=0;
         service_time=0;
         finishing =false; ///client not finish him task
         waitting_time=0;
         final_time=0;
         numberOfCasher=-1;
         hasInterruption=false;
        }

        int getArrival(){return arrival_time;}
        int getService(){return service_time;}
        int getFinalTime(){return final_time;}
        int getWaittingTime(){return waitting_time;}
        int getAroundTime(){return around_time;}
        int getNumberOFCasher(){return numberOfCasher;}
        LinkedList<int> getInterruption(){return interuption_time;}
        bool getFinishingFlag(){return finishing;}
        bool getHasInterruption(){return hasInterruption;}
    protected:

    private:

        int arrival_time,service_time,waitting_time,final_time,around_time;
        LinkedList<int> interuption_time;
        bool finishing;
        bool hasInterruption;
        int numberOfCasher;
};

#endif // CLIENT_H
