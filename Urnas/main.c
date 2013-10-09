#include <stdio.h>
#include <stdlib.h>
#include "School.h"
#include "tree.h"
#include "queue.h"

int main()
{
    /*node *root;
    root=NULL;
    int menu=0;
    do{
    addTruck();
    process();
    printf("Enter 1 to continue the simulation and enter 2 to finish and print the report./n");
    scanf("%d",&menu);
    } while (menu==1);*/
     int i=0;
     front=NULL;
     printf(" \n1. Push to Queue");
     printf(" \n2. Pop from Queue");
     printf(" \n3. Display Data of Queue");
     printf(" \n4. Exit\n");
     while(1)
     {
          printf(" \nChoose Option: ");
          scanf("%d",&i);
          switch(i)
          {
                case 1:
                {
                     struct school school;
                     printf("\nEnter a valueber to push into Queue: ");
                     createSchool(&school,1245,1);
                     push(school);
                     display();
                     break;
                }
                case 2:
                {
                     delQueue();
                     display();
                     break;
                }
                case 3:
                {
                     display();
                     break;
                }
                case 4:
                {
                     exit(0);
                }
                default:
                {
                     printf("\nwrong choice for operation");
                }
          }
     }
	return 0;
}



void addTruck(){
    double random_number = rand() / (double)RAND_MAX;
    if(random_number <=0.6){
        //addtoquee
    }
}

void process(node *root){
    //retrivefromquee
    int boxes[500];
    struct school school;
    int i=0;
    for(i;i<500;i++){
        createSchool(&school,boxes[i],1);
        node *tmp;
    tmp = search(&root, school);
    if (tmp)
    {
        createSchool(&root->data,&root->data.code,&root->data.code+1);
    }
    else
    {
        insert(&root,school);
    }
    }
}
