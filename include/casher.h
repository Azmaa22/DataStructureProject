#ifndef CASHER_H
#define CASHER_H


class casher
{
    private:
        int serving_time;
        bool serving_flag;

    public:
        casher() {
           serving_time=0;
           serving_flag=false; ///not work
        }
        casher(int t,bool f){
         serving_time=t;
         serving_flag=f;
        }

        void setserving_time(int time){serving_time=time;}
        void setServingFlag(bool flag){serving_flag=flag;}

        int getserving_time(){return serving_time;}
        bool getSrvingFlag(){return serving_flag;}

};

#endif // CASHER_H
