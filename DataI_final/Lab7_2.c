#include <stdio.h>
#include <stdbool.h>
#define maxsize  5



typedef struct node{
    int data;
    struct node *next;
}node;

node *Top=NULL;
int size=0;

bool isEmpty()
{
    if(Top==NULL)
        return true;
    else
        return false;
}

bool isFull(){
if(size==maxsize)
    return true;
return false;
}



void push(int data) {

    if (isFull())
    printf ( "\nStack is full\n" );
    else
    {
        node *new_node=(node*)malloc(sizeof(node));
        new_node->data=data;
        new_node->next=Top;
        Top=new_node;
        size++;
    }

}

int pop()
{
  int data=-1;
  if (isEmpty())
     printf("\nStack is Empty\n");
  else{
        node *ptr=Top;
        data=Top->data;
        Top=Top->next;
        ptr->next=NULL;
        size--;

  }
  return data;
}

int peek()
{
    if(isEmpty()){
        printf("\nStack is Empty\n");
        return -1;
    }
    else
        return Top->data;

}
void display()
{
  int i;
  if ( isEmpty())
      printf("\nStack is Empty\n");
  else{
        node *ptr=Top;
        while(ptr!=NULL){
            printf("\n %d ",ptr->data);
            ptr=ptr->next;
        }
    }
}

int main()
{
   int item, option;

   do
   {
      printf("\n *****MAIN MENU*****");
      printf("\n 1. PUSH");
      printf("\n 2. POP");
      printf("\n 3. PEEK");
      printf("\n 4. DISPLAY");
      printf("\n 5. EXIT");
      printf("\n Enter your option: ");
      scanf("%d", &option);

     switch(option)
     {
        case 1:
            printf("\n Enter the number to be pushed on stack: ");
            scanf("%d", &item);
            if(isFull())
                printf("\nStack is Full\n");
            else
                push(item);
        break;

        case 2:
            if(isEmpty())
               printf("\nStack is Empty\n");
            else
            {
                 item = pop();
                 printf("\n The value deleted from stack is: %d", item);
            }
        break;

        case 3:
            item=peek();
            if (item != -1)
               printf("\n The value stored at top of stack is: %d", item);
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Bye ...\n"); break;

        default: printf("Unknown option\n"); break;

     }//end switch
   }while(option !=5);
  return 0;
}
