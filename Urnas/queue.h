 #include<stdio.h>
 #include<conio.h>
 #include<stdlib.h>
 struct Node
 {
        struct school Data;
        struct Node* next;
 }*rear, *front;

void delQueue()
{
       struct Node *temp, *var=rear;
      if(var!=NULL)
      {
             rear = rear->next;
             free(var);
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
}

void display()
{
     struct Node *var=rear;
     if(var!=NULL)
     {
           printf("\nElements are as:  ");
           while(var!=NULL)
           {
                printf("\nCode:%d\n",var->Data.code);
                printf("Ballot Boxes: %d\n",var->Data.cantboxes);
                var=var->next;
           }
     printf("\n");
     }
     else
     printf("\nQueue is Empty");
}

