#ifndef CLIENT_H
#define CLIENT_H

#include "LinkedList.h"
class client
{
    public:

        void setArrival(int t){arrival_time=t;}
        void setService(int t){service_time=t;}
        void setInteruption(LinkedList<int> L){
             interuption_time=L;

            }
        void setFinishing(bool f){
        finishing=f;}
        client(int t1,int t2){
          arrival_time=t1;
          service_time=t2;
          final_time=0;
          waitting_time=0;
          finishing=false;
        }
        client(){
         arrival_time=0;
         service_time=0;
         finishing =false; ///client not finish him task
         waitting_time=0;
         final_time=0;
        }
        int getArrival(){return arrival_time;}
        int getService(){return service_time;}
        int getFinalTime(){return final_time;}
        int getWaittingTime(){return waitting_time;}
        //void getInterruption(){interuption_time.Display();}
        LinkedList<int> getInterruption(){return interuption_time;}
        bool getFlag(){return finishing;}
    protected:

    private:

        int arrival_time,service_time,waitting_time,final_time;
        LinkedList<int> interuption_time;
        bool finishing;
};

#endif // CLIENT_H
