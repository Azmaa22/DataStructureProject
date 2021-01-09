#ifndef CASHER_H
#define CASHER_H


class casher
{
    public:
        casher() {
           openning_time=0;
           serving_flag=false; ///not work
        }
        casher(int t,bool f){
         openning_time=t;
         serving_flag=f;
        }
        void setOpenningTime(int time){openning_time=time;}
        void setServingFlag(bool flag){serving_flag=flag;}
        int getOpenningTime(){return openning_time;}
        bool getSrvingFlag(){return serving_flag;}

    protected:

    private:
        int openning_time;
        bool serving_flag;
};

#endif // CASHER_H
