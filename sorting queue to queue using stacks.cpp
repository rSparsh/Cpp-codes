#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int stk[100];
    int top;
}stack;

void push (stack* a,int element)
{
    int num;
    if (a->top == (100 - 1))
    {
        printf ("Stack is Full\n");
        return;
    }
    else
    {
        a->top = a->top + 1;
        a->stk[a->top] = element;
    }
    return;
}

int pop (stack* a)
{
    int num;
    if (a->top == - 1)
    {
        printf ("Stack is Empty\n");
        return (a->top);
    }
    else
    {
        num = a->stk[a->top];
        a->top = a->top - 1;
    }
    return(num);
}

struct Queue { 
    int front, rear, size; 
    unsigned capacity; 
    int* array; 
}; 
  
struct Queue* createQueue(unsigned capacity) 
{ 
    struct Queue* queue = (struct Queue*)malloc( 
        sizeof(struct Queue)); 
    queue->capacity = capacity; 
    queue->front = queue->size = 0; 
  
    // This is important, see the enqueue 
    queue->rear = capacity - 1; 
    queue->array = (int*)malloc( 
        queue->capacity * sizeof(int)); 
    return queue; 
} 
  
int isFull(struct Queue* queue) 
{ 
    return (queue->size == queue->capacity); 
} 
  
int isEmpty(struct Queue* queue) 
{ 
    return (queue->size == 0); 
} 
  
void enqueue(struct Queue* queue, int item) 
{ 
    if (isFull(queue)) 
        return; 
    queue->rear = (queue->rear + 1) 
                  % queue->capacity; 
    queue->array[queue->rear] = item; 
    queue->size = queue->size + 1; 
} 
  
int dequeue(struct Queue* queue) 
{ 
    if (isEmpty(queue)){
        printf("Queue is empty");
        return 0;
    }
    int item = queue->array[queue->front]; 
    queue->front = (queue->front + 1) 
                   % queue->capacity; 
    queue->size = queue->size - 1; 
    return item; 
} 
  
int front(struct Queue* queue) 
{ 
    if (isEmpty(queue)){
        printf("Queue is empty");
        return 0;
    }
    return queue->array[queue->front]; 
} 
  
int rear(struct Queue* queue) 
{ 
    if (isEmpty(queue)){
        printf("Queue is empty");
        return 0;
    }
    return queue->array[queue->rear]; 
} 

void display (stack* s)
{
    int i;
    if (s->top == -1)
    {
        printf ("Stack is empty\n");
        return;
    }
    else
    {
        printf ("Final stack is \n");
        for (i = s->top; i >= 0; i--)
        {
            printf ("%d\n", s->stk[i]);
        }
    }
    printf ("\n");
}

void sort(struct Queue* queue){
    stack s1;
    s1.top = -1;
    stack s2;
    s2.top = -1;

    for(int i=queue->front;i<queue->front+queue->size;i++){
        push(&s1,queue->array[i]);
    }

    while(!(s1.top==-1)){
        int temp = s1.stk[s1.top];
        pop(&s1);
        while(!(s2.top==-1) && s2.stk[s2.top]<temp){
            push(&s1,s2.stk[s2.top]);
            pop(&s2);
        }
        push(&s2,temp);
    }

    display(&s2);
}


int main() 
{ 
    int size, element, x;
    stack steck;
    steck.top = -1;
    printf("Enter size of queue : ");
    scanf("%d",&size);
    struct Queue* queue = createQueue(1000); 
  
    for(int i=0;i<size;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&element);
        enqueue(queue, element); 
    }

    sort(queue);
    return 0; 
} 
