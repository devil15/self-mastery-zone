#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct node
{
  int data;
  struct node *link;
}*front,*rear;

void insert()
{
  struct node *temp;
  temp=(struct node*)malloc(sizeof(struct node));
  printf("Enter value to be inserted \n");
  scanf("%d", &temp->data);
  temp->link=NULL;
  if(rear ==NULL)
  {
    front=rear=temp;
  }
  else
  {
      rear->link=temp;
      rear=temp;
  }
}

void delete()
{
  struct node *temp;
   temp=front;
   if (front==NULL)
   {
     printf("queue is empty\n");
     front=rear=NULL;
   }
   else
   {
      printf("removed element is %d\n",front->data);
      front=front->link;
      free(temp);
   }
}
void check()
{
    if (front == NULL)
        printf("\nQueue is empty\n");
    else
        printf("*************** Elements are present in the queue **************\n");
}

// returns first element of queue
void first_element()
{
    if (front == NULL)
    {
        printf("**************** The queue is empty ****************\n");
    }
    else
        printf("**************** The front element is %d ***********\n", front->data);
}
void queue_size()
{
    struct node *temp;

    temp = front;
    int cnt = 0;
    if (front  ==  NULL)
    {
        printf(" queue empty \n");
    }
    while (temp)
    {
        printf("%d  ", temp->data);
        temp = temp->link;
        cnt++;
    }
    printf("********* size of queue is %d ******** \n", cnt);
}

int main(int argc, char const *argv[]) {
  int choice, value;

    while(1)
    {
        printf("enter the choice \n");
        printf("1 : create an empty queue \n2 : Insert element\n");
        printf("3 : Dequeue an element \n4 : Check if empty\n");
        printf("5. Get the first element of the queue\n");
        printf("6. Get the number of entries in the queue\n");
        printf("7. Exit\n");
        scanf("%d", &choice);
        switch (choice)    // menu driven program
        {
        case 1:
            printf("Empty queue is created with a capacity of %d\n", MAX);
            break;
        case 2:
            insert();
            break;
        case 3:
            delete();
            break;
        case 4:
            check();
            break;
        case 5:
            first_element();
            break;
        case 6:
            queue_size();
            break;
        case 7:
            exit(0);
        default:
            printf("wrong choice\n");
            break;
        }
    }
  return 0;
}
