#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef int stackEntrytype;
#define Max 10

typedef struct stack{
    int top;
    stackEntrytype arr[Max];
}Stack;

void CreateStack(Stack *s){
s->top=-1;
}

bool IsStackFull(Stack *s){
    return s->top==Max-1;

}

void Push(Stack *s, stackEntrytype item){
    if(IsStackFull(s)){
        printf("Stack is full.");
        exit(1);
    }else{
        s->arr[++s->top]=item;
    }

}

bool IsStackEmpty(Stack *s){
    return s->top==-1;
}

void Pop(Stack *s){
    if(IsStackEmpty(s)){
        printf("Stack is empty.");
        exit(1);

    }else{
        printf("%d",s->arr[s->top--]);
    }
}

void Display(Stack *s) {
    for (int i = 0; i <= s->top;i++) {
        printf("%d\t",s->arr[i]);
    }
}

int main(){
Stack s;
CreateStack(&s);
for (int i =0; i < 10; i++) {
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
return 0;
}
