#include <stdio.h>
#include <stdlib.h>
#include "School.h"
#include "tree.h"
#include "queue.h"

int main()
{
    front=NULL;
    struct school centinel;
    push(centinel); //only way i found to avoid error when queue was refilled after being totally emptied
    node *root;
    root=NULL;
    int menu=0;
    do{
    addTruck();
    process(root);
    printf("Enter 1 to continue the simulation and enter 2 to finish and print the report.\n");
    scanf("%d",&menu);
    } while (menu==1);
    /*struct school school;
                    int random_number = rand() % 10;
                     createSchool(&school,(int) random_number,1);
                     push(school);
                     display();
                     int random_number2 = rand() % 10;
                     createSchool(&school,(int) random_number2,1);
                     push(school);
                     display();
                     struct Node *var=delQueue();
                     printf("\nCode:%d\n",var->Data.code);
                    printf("Ballot Boxes: %d\n",var->Data.cantboxes);*/



	return 0;
}



void addTruck(){
    if(rand()%10 <=6){
            int i=0;
            for(i;i<300;i++){
            int random_number = rand() % 9999;

                    struct school school;
                     createSchool(&school,random_number,1);
                     push(school);

    }

    }

}

void process(node *root){
    int i=0;
    if(sizeofqueue()>0){
    for(i;i<100;i++){

                    printf("%d",sizeofqueue());
     struct school school;
     struct Node *node=delQueue();
     createSchool(&school,node->Data.code,1);
        struct  node *tmp;
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
}
