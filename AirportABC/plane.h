#include <time.h>

#define COMPANY 3
#define VALUES 9

struct plane
{
    time_t request;
    char company;
    int first;
    int second;
    int third;
    time_t landed;
}c;
char randomize_company();
int set_number();

char randomize_company(){
    int random = (rand() % COMPANY) + 1;
    char company;
    if (random == 1){
        company = 'A';
    } if(random == 2){
        company = 'B';
    } else{
        company = 'C';
    }

    return company;
}

int set_number(){
    int random = (rand() % VALUES) + 1;
    return random;
}


/**
Initialises a plane and it pushes into a queue that represents the assembly line
*/
void create_plane(){
    struct plane plane;
    time(&plane.request);
    plane.company = randomize_company();
    plane.first = set_number();
    plane.second = set_number();
    plane.third = set_number();

    push(plane);
}

/**
Set the completion time for a plane when it is poped from the assembly line
*/
void set_landing_time(struct plane *plane ){
    plane->landed = time(&plane->landed);
}
