#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int queueElement;
typedef enum{FALSE,TRUE} boolean;

typedef struct node{
    queueElement data;
    struct node *next;
}Node;

typedef struct queue{
    int count;
    Node *front;
    Node *rear;
    boolean full;
}Queue;

void createQueue(Queue *q){
    q->count=0;
    q->front=q->rear=NULL;
    q->full=FALSE;
}

boolean IsQueueFull(Queue *q){
   return q->full;

}

boolean IsQueueEmpty(Queue *q){
    return q->count==0;
}

void insert (Queue *q, queueElement item){
    Node *np;
    np= (Node*)malloc(sizeof(Node));

    if(IsQueueFull(q)){
        printf("Queue is full");
        exit(1);
    }else{
        np->data=item;
        np->next=NULL;
        if(IsQueueEmpty(q)){
            q->rear=q->front=np;
        }else{
            q->rear->next=np;
            q->rear=np;
        }
        q->count++;
    }
}

void Remove(Queue *q){
    Node *np;
    if(IsQueueEmpty(q)){
        printf("Queue is empty");
        exit(1);
    }
    printf("%d",q->front->data);
    np=q->front;
    q->front=np->next;
    if(q->front==NULL){
        q->rear=NULL;
    }
    free(np);
    q->count--;
}

void Display(Queue *q){
    Node *np;
    np=q->front;
    while(np !=NULL){
        printf("%d\t",np->data);
        np=np->next;
    }
}


void main(){
    Queue q;
    createQueue(&q);
    for(int i=0;i<10;i++){
        insert(&q,i+1);
    }
    Display(&q);
    printf("\n\n");
    Remove(&q);
    printf("\n");
    Display(&q);
    printf("\n\n");
    Remove(&q);
    printf("\n");
    Display(&q);
}

