    #include<stdio.h>
    #include<stdlib.h>
    #include<stdbool.h>

    typedef int listElement;
    typedef enum{FALSE,TRUE} boolean;

    typedef struct node{
        int data;
        struct node *next;
    }Node;

    typedef struct list{
        Node *head;
        int count;
        boolean full;
    }List;

    void createList(List *l){
        l->count=0;
        l->head=NULL;
        l->full=FALSE;
    }

    boolean IsListEmpty(List *l){
       return l->count==0;
    }

    void InsertLast(List *l,listElement item){
        Node *np;
        np= (Node*) malloc(sizeof(Node));

        if(np==NULL){
            printf("List is full");
            l->full=TRUE;
            exit(1);
        }
        np->data=item;
        np->next=NULL;
        if(l->head==NULL){
            l->head=np;
            l->count++;
        }else{
            Node *temp= l->head;
            while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=np;
        l->count++;
        }
    }

    void InsertFirst(List *l,listElement item){
         Node *np;
        np= (Node*) malloc(sizeof(Node));

        if(np==NULL){
            printf("List is full");
            l->full=TRUE;
            exit(1);
        }
        np->data=item;
        np->next=l->head;
        l->head=np;
        l->count++;
    }

    void InsertMiddle(List *l,int p,listElement item){
         Node *np;
        np= (Node*) malloc(sizeof(Node));

        if(np==NULL){
            printf("List is full");
            l->full=TRUE;
            exit(1);
        }
        else if(p<1 || p>l->count){
            printf("Given Position is not available");
            exit(1);
        }
        np->data=item;

        Node *temp=l->head;
        int i=1;
        while(i<p-1){
        temp=temp->next;
        i++;
      }
      np->next=temp->next;
      temp->next=np;
      l->count++;

    }

    void DeleteLast(List *l){
        if(IsListEmpty(l)){
            printf("List is Empty");
            exit(1);
        }else if(l->head->next==NULL){
                 printf("%d\n",l->head->data);
                free(l->head);
                l->count--;
            }
         else{

        Node *temp=l->head;
        while(temp->next->next!=NULL){

        temp=temp->next;
        }
        printf("%d\n",temp->next->data);
        free(temp->next);
        temp->next=NULL;
        l->count--;
        }
    }

    void DeleteFirst(List *l){

        if(IsListEmpty(l)){
                printf("List is Empty");
                exit(1);
        }
            printf("%d\n",l->head->data);
            Node *np=l->head;
            l->head=l->head->next;
            free(np);
            l->count--;
        }

    void DeleteMiddle(List *l,int p){
                if(IsListEmpty(l)){
                printf("List is Empty");
                exit(1);
        }
        if(p<1 || p> (l->count)){

            printf("Given Position is not available");
            exit(1);

        }
        else{

            if(l->head->next==NULL){
                printf("%d\n",l->head->data);
                DeleteFirst(l);
            }
            else{
                    Node *temp=l->head;
                    int i=1;
                    while(i<p-1){
                        temp=temp->next;
                        i++;

                    }
                    Node *np=temp->next;
                    temp->next=np->next;
                    printf("%d\n",np->data);
                    free(np);
                    l->count--;

            }

    }
    }

    void Display(List *l){
        Node *np;
        np = l->head;
        while(np) {
            printf("%d \t",np->data);
            np = np->next;
        }
    }

    int main(){
        List l;
        createList(&l);
        for(int i=0;i<10;i++){
            InsertLast(&l,i+1);
        }
        Display(&l);
        printf("\n");
        InsertFirst(&l,40);
        Display(&l);
        printf("\n");
        InsertMiddle(&l,3,90);
        Display(&l);
        printf("\n");
        DeleteLast(&l);
        Display(&l);
        printf("\n");
        DeleteFirst(&l);
        Display(&l);
        printf("\n");
        DeleteMiddle(&l,3);
        Display(&l);
        printf("\n");

    }
