#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int queueElement;
#define MAX 100

typedef struct queue{
    queueElement arr[MAX];
    int front;
    int rear;
    int count;

}Queue;

void CreateQueue(Queue *q){
    q->front=-1;
    q->rear=-1;
    q->count=0;
}

bool IsQueueFull(Queue *q){
    return q->rear==MAX-1;
}

void Insert(Queue *q,queueElement item){
    if(IsQueueFull(q)){
        printf("Queue is full.");
        exit(1);
    }

    if(q->front==-1){
        q->front++;
    }
        q->arr[++q->rear]=item;
        q->count++;

}

bool IsQueueEmpty(Queue *q){
    return q->count==0;
}

void Remove(Queue *q){
    if(IsQueueEmpty(q)){
       printf("Queue is empty.");
       exit(1);
    }
        printf("Removed value: %d",q->arr[q->front]);
        if(q->rear==q->front){
            q->rear=q->front=-1;
            q->count=0;
        }else{
        q->front++;
        q->count--;
        }
}

void QueueSize(Queue *q){
    printf("Queue size is: %d", q->count);
}

void Display(Queue *q){
    for(int i=q->front;i<=q->rear;i++){
        printf("%d\t",q->arr[i]);
    }

}

int main(){
    Queue q;
    CreateQueue(&q);
    for(int i=0;i<10;i++){
        Insert(&q,i+1);
    }
    Display(&q);
    printf("\n");
    QueueSize(&q);
    printf("\n\n");
    Remove(&q);
    printf("\n");
    Display(&q);
    printf("\n");
    QueueSize(&q);
    printf("\n");
    printf("\n");
    Remove(&q);
    printf("\n");
    Display(&q);
    printf("\n");
    QueueSize(&q);
    printf("\n");

}

