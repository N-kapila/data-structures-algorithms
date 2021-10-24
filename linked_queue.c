#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int queueElement;
typedef enum{FALSE,TRUE} Boolean;

typedef struct node{
    queueElement data;
    struct node *next;
}Node;

typedef struct queue{
    Node *front;
    Node *rear;
    queueElement count;
    Boolean full;
}Queue;

void CreateQueue(Queue *q){
    q->front=q->rear=NULL;
    q->count=0;
    q->full=FALSE;
}

Boolean IsQueueFull(Queue *q){
    return q->full;
}

Boolean IsQueueEmpty(Queue *q){
    return q->count==0;
}

void Insert(Queue *q,queueElement item)
{
    Node *np;
    np=(Node*)malloc(sizeof(Node));

    if(np==NULL){
        printf("Queue is full");
        q->full=TRUE;
        exit(1);
    }else{
        np->data=item;
        np->next=NULL;
        if(IsQueueEmpty(q)){
            q->front=q->rear=np;
            q->count++;
        }else{
            q->rear->next=np;
            q->rear=np;
            q->count++;
        }
    }
}

void Remove(Queue *q){
    if(IsQueueEmpty(q)){
        printf("Queue is Empty");
        exit(1);
    }else{
        printf("%d",q->front->data);
        Node *np;
        np=q->front;
        q->front=np->next;
        if(q->front==NULL){
            q->rear=NULL;

        }
        free(np);
        q->count--;
    }
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
        CreateQueue(&q);
        for(int i=0;i<10;i++){
        Insert(&q,i+1);
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
        printf("\n\n");
}
