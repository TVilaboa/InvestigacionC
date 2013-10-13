#include <time.h>

struct truck{
    struct school schools[500];
    int hours;
};


void createTruck(int hour){
    struct truck truck;
    int i=0;
            for(i;i<500;i++){
            int random_number = rand() % 9999;

                    struct school school;
                     createSchool(&school,random_number,1);
                     truck.schools[i]=school;

}

   truck.hours=hour;
    push(truck);
}




