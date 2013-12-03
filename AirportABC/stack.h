#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 50

double stack[MAX_SIZE];
void pushStack();
double pop();
//void traverse();
int is_empty();
double top_element();
int top = -1;

void pushStack(double value)
{
   top++;
   stack[top] = value;
}

double pop()
{
   double element;

   if ( top == -1 )
      return 0;

   element = stack[top];
   top--;

   return element;
}

/**void()
{
   int d;

   if ( top == - 1 )
   {
      printf("Stack is empty.\n\n");
      return;
   }

   printf("There are %d elements in stack.\n", top+1);

   for ( d = top ; d >= 0 ; d-- )
      printf("%d\n", stack[d]);
   printf("\n");
}
*/

int is_empty()
{
   if ( top == - 1 )
      return 1;
   else
      return 0;
}

double top_element()
{
   return stack[top];
}
