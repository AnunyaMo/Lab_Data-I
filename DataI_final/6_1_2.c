#include<stdio.h>
#include<stdlib.h>
#define maxsize 10

void enqueue(int);
int dequeue();
void displayQ();

typedef struct node{
    int data;
    struct node *next;
}node;

    node *Front=NULL;
    node *Rear=NULL;
    int size=0;

int main(){
    int i,n;

    for(i=1;i<1000;i*=2)
        enqueue(i);
    displayQ();

    scanf("%d",&n);
    for(i=1;i<=n;i++)
        dequeue();
    displayQ();

    for(i=10;i>=1;i/=2)
        enqueue(i);
    displayQ();
}

void enqueue(int data){
    if(size>=maxsize)
        printf("\nQueue is Full\n");
    else{
        node *new_node=(node*)malloc(sizeof(node));
        new_node->data=data;
        new_node->next=NULL;
        if(Front==NULL){
            Front=new_node;
            Rear=new_node;
        }
        else{
            Rear->next=new_node;
            Rear=new_node;
        }
        size++;
    }
}

int dequeue(){
    int data;
    if(size==0){
        printf("\nQueue is Empty\n");
        return -1;
    }
    else{
        node *ptr=Front;
        Front=Front->next;
        data=ptr->data;
        ptr->next=NULL;
        free(ptr);
        size--;

        return data;
    }
}

void displayQ(){
    int i;
    if(size==0)
        printf("\nQueue is Empty\n");
    else{
        printf("\nfront[");
        node *ptr=Front;
        while(ptr!=NULL){
            printf(" %d ",ptr->data);
            ptr=ptr->next;
        }
        printf("]rear\n");
    }
}
