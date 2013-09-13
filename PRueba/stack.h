#include <stdbool.h>
#include <assert.h>

typedef struct{
void *elems;
int elemSize;
int logLength;
int allocLength;
} stack;

void StackNew(stack *s,int elemSize);
void StackDispose(stack *s);
bool StackEmpty(const stack *s);
void StackPush(stack *s, const void *elemAddr);
void StackPop(stack *s, void *elemAddr);

#define kInitialAllocationSize 4
void StackNew(stack *s,int elemSize)
{
assert(elemSize > 0);
s->elemSize = elemSize;
s->logLength = 0;
s->allocLength = kInitialAllocationSize;
s->elems = malloc(kInitialAllocationSize * elemSize);
assert(s->elems != NULL);
}


void StackDispose(stack *s)
{
free(s->elems);
}



bool StackEmpty(const stack *s)
{
return s->logLength == 0;
}

void StackPush(stack *s, const void *elemAddr)
{
void *destAddr;
if(s->logLength == s->allocLength){
s->allocLength *= 2;
s->elems = realloc(s->elems, s->allocLength * s->elemSize);
assert(s->elems != NULL);
}
destAddr = (char *)s->elems + s->logLength * s->elemSize;
memcpy(destAddr, elemAddr, s->elemSize);
s->logLength++;
}

void StackPop(stack *s, void *elemAddr)
{
const void *sourceAddr;
assert(!StackEmpty(s));
s->logLength--;
sourceAddr = (const char *)s->elems + s->logLength * s->elemSize;
memcpy(elemAddr, sourceAddr, s->elemSize);
}
