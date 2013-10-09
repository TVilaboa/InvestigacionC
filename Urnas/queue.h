 #include<stdio.h>
 #include<conio.h>
 #include<stdlib.h>

 struct Node
 {
        struct school Data;
        struct Node* next;
 }*rear, *front;

int siz=0;


node* delQueue()
{
       struct Node *temp, *var=rear;
      if(var!=NULL)
      {
             rear = rear->next;
             siz-=1;
             return var;
      }
      else
      printf("\nQueue Empty");
}

void push(struct school value)
{
     struct Node *temp;
     temp=(struct Node *)malloc(sizeof(struct Node));
     temp->Data=value;
     if (front == NULL)
     {
           front=temp;
           front->next=NULL;
           rear=front;
     }
     else
     {
           front->next=temp;
           front=temp;
           front->next=NULL;
     }
     siz+=1;
}

void display()
{
     struct Node *var=rear;
     if(var!=NULL)
     {
           printf("\nElements are as:  ");
           while(var!=NULL)
           {
                //recorrer arreglo de school
                var=var->next;
           }
     printf("\n");
     }
     else
     printf("\nQueue is Empty");
}

int sizeofqueue(){
    return siz;
}

