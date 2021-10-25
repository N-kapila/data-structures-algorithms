#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int listElement;
typedef enum{FALSE,TRUE} boolean;
#define MAX 100

typedef struct list{
    int count;
    listElement arr[MAX];
}List;

void CreateList(List *l)
{
    l->count=0;
}

boolean IsListFull(List *l){
    return l->count==MAX;
}

boolean IsListEmpty(List *l){
    return l->count==0;
}

/*int ListSize(List *l)
{
    return l->count;
}*/

void InsertLast(List *l,listElement item){
    if(IsListFull(l)){
        printf("List is full");
        exit(1);
    }else{
        l->arr[l->count]=item;
        l->count++;
    }

}

void InsertList(List *l,int p, listElement item){
    if(IsListFull(l)){
        printf("List is full");
        exit(1);
    }else if(p<1 || p> l->count){
        printf("Position is invalid");
        exit(1);
    }else{
        for (int i = l->count ; i >= p; i--) {

           l->arr[i] = l->arr[i-1];

        }
        l->arr[p-1]=item;
        l->count++;
    }
}

void ReplaceList(List *l,int p, listElement item){
    if(IsListEmpty(l)){
        printf("Can not replace.List is Empty");
        exit(1);
    }else if(p<1 || p> l->count){
        printf("Given position is not available in the list");
        exit(1);
    }else{
        l->arr[p-1]=item;
    }
}

void DeleteList(List *l,int p){
    if(IsListEmpty(l)){
        printf("Can not delete.List is Empty");
        exit(1);
    }else if(p<1 || p> l->count){
        printf("Given position is not available in the list");
        exit(1);
    }else{
        for (int i = p-1; i < l->count-1; i++) {
                l->arr[i] = l->arr[i+1];
        }
        l->count--;
    }
}

void RetriveList(List *l, int p){
    if(IsListEmpty(l)){
        printf("List is Empty");
        exit(1);
    }else if(p<1 || p> l->count){
        printf("Given position is not available in the list");
        exit(1);
    }else{
        printf("%d",l->arr[p-1]);
    }
}

void Display(List *l){
    for (int i = 0; i < l->count;i++) {
            printf("%d\t",l->arr[i]);
    }
}

void main(){
    List l;
    CreateList(&l);
    for(int i=0;i<10;i++){
            InsertLast(&l,i+10);
    }
    Display(&l);
    printf("\n");
    InsertList(&l,3,100);
    Display(&l);
    ReplaceList(&l,6,1500);
    printf("\n");
    Display(&l);
    DeleteList(&l,5);
    printf("\n");
    Display(&l);
    printf("\n");
    RetriveList(&l,5);
    printf("\n");
}
