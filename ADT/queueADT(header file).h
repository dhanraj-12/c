#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
    void *dataptr;
    struct node *next;

}QUEUE_NODE;

typedef struct{
    QUEUE_NODE *front;
    QUEUE_NODE *rear;
    int count ;
}QUEUE;

QUEUE* createQueue(void){
    QUEUE *queue;
    queue=(QUEUE*)malloc(sizeof(QUEUE));
    if (queue){
        queue->front=NULL;
        queue->rear=NULL;
        queue->count=0;
    
    }
    return queue;
}

bool enqueue(QUEUE* queue, void *itemptr){
QUEUE_NODE *newptr;
if(!(newptr = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE))))
return false;
newptr->dataptr=itemptr;
newptr->next=NULL;
if(queue->count==0){
    queue->front=newptr;
    
}
else{
    queue->rear->next=newptr;
    
}
queue->rear=newptr;
(queue->count)++;
}

bool dequeue(QUEUE *queue,void **itemptr){
    QUEUE_NODE * deleteloc;
    if(!queue->count)
    return false;
    *itemptr=queue->front->dataptr;
    deleteloc=queue->front;
    if(queue->count==1){
        queue->rear = NULL;
        queue->front = NULL;

    }
    else {queue->front=queue->front->next;}
        (queue->count)--;
        free(deleteloc);
        return true;
}
bool queuefront (QUEUE* queue, void** itemptr)
{
//Statements
if (!queue->count)
return false;
else
{
*itemptr = queue->front->dataptr;
return true;
} // else
}
bool queueRear(QUEUE *queue, void ** itemptr){
    if(!queue->count)
    return false;
    else{
    *itemptr=queue->rear->dataptr;
    return false;
    }
}

bool emptyqueue(QUEUE *queue){
return (queue->count==0);
}
bool fullqueue(QUEUE *queue){
    QUEUE_NODE *temp;
    temp=(QUEUE_NODE *)malloc(sizeof(QUEUE_NODE));
    if(temp){
        free(temp);
        return true;
    }
    return false;
}
int queuecount(QUEUE *queue){
    return queue->count;
}
QUEUE* destroyqueue(QUEUE *queue){
    QUEUE_NODE *deleteptr;
    if(queue){
        while(queue->front!=NULL){
            free(queue->front->dataptr);
            deleteptr=queue->front;
            queue->front=queue->front->next;
            free(deleteptr);
        }
        free(queue);
    }return NULL;
}

  