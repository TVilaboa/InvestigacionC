#include <stdio.h>
#include <stdlib.h>
#include "School.h"
#include "tree.h"


int main()
{
    node *root;
    root=NULL;
    int menu=0;
    do{
    addTruck();
    process();
    printf("Enter 1 to continue the simulation and enter 2 to finish and print the report./n");
    scanf("%d",&menu);
    } while (menu==1);
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
