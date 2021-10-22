#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int StackEntryType;

typedef struct node{
    StackEntryType data;
    struct node *next;
}Node;

typedef struct stack{
    int element;
    Node *top;
}Stack;

void CreateStack (Stack *s){
    s->top= NULL;
    s->element = 0;
}

void Push(Stack *s, StackEntryType item){
    Node *np;
    np= (Node*)malloc(sizeof(Node));

    if(np==NULL){
        printf("Stack is full.");
        exit(1);
    }else{
        np-> data= item;
        np-> next = s->top;
        s-> top = np;
        s-> element++;

    }
}

bool IsStackEmpty(Stack *s){

    return s->top == NULL;
}

void Pop(Stack *s){
    if(IsStackEmpty(s)){
        printf("Stack is empty.");
        exit(1);
    }else{
        Node *np;
        printf("%d",s->top->data);
        np=s->top;
        s->top=np->next; // s->top=s->top>next;
        s->element--;
        free(np);
    }

}

void Display(Stack *s){
    Node *np;
    np=s->top;
    while(np !=NULL){
        printf("%d\t",np->data);
        np=np->next;
    }
}

int main(){
    Stack s;
    CreateStack(&s);
    for(int i=0;i<10;i++){
          Push(&s,i+1);
    }
    Display(&s);
    printf("\n");
    Pop(&s);
    printf("\n");
    Display(&s);
    printf("\n");
    Pop(&s);
    printf("\n");
    Display(&s);
    printf("\n");
}



