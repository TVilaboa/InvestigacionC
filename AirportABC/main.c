#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"

double get_average(double time,int counter);

int main()
{
    int counter = 0; //counter to calculate actual waiting time

    double average;
    double time = 0;

    int counter_A = 0;
    int counter_B = 0;
    int counter_C = 0;

    front = NULL;
    int menu = 0;

    do{

        addplane();
        if(sizeofqueue() > 5){ // 5 planes must be over flying at ALL times

            double time_elapsed; // time for every flying between request and actual
                                    // landing

            struct plane flight;
            struct Node *node = delQueue();
            flight = node->data;
            set_landing_time(&flight);

            flight.company = randomize_company();
            flight.first = set_number();
            flight.second = set_number();
            flight.third = set_number();

            if(flight.company == "A"){
                counter_A++;
            }if(flight.company == "B"){
                counter_B++;
            }if(flight.company == "C"){
                counter_C ++;
            };

            printf("\n FLIGHT \n");
            printf("%s", asctime(localtime(&flight.request)));
            printf("%s", asctime(localtime(&flight.landed)));
            printf("\n");

            time_elapsed = difftime(flight.landed,flight.request);
            printf("\n Time elapsed between request and Landing: %f \n", time_elapsed);

            time += time_elapsed;

            addplane();
            counter ++;
       }

        printf(" \nEnter 1 to continue the simulation and enter 2 to finish and print average time for assembly.\n");
        scanf("%d",&menu);

    }while(menu == 1);

    int i;
    for(i =0; i < 10; i++){
        int random = (rand() % 3) + 1;
        printf(" % 02d", random);
    }


    average = get_average(time,counter);

    printf("\n Average waiting time for landing is %f  seconds \n", average);
    printf("\n A %02d \n",counter_A);
    printf("\n B %02d \n",counter_B);
    printf("\n C %02d \n",counter_C);

    return 0;
}

/**
Adds a plane to the simulation
*/
void addplane(){
    create_plane();

    return 0;
}

double get_average(double time, int counter){
    double average = time / counter;
    return average;
}
