//program to implements various functions on queues using linked list
#include <stdio.h>

struct node
{
    int i;
    struct node *ptr;
}*front,*rear,*front1;

int count;//stores queue size



/* Enqueing the queue */
void enqueue(int d)
{
    struct node* temp;
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->ptr = NULL;
        rear->i = d;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->ptr = temp;
        temp->i = d;
        temp->ptr = NULL;

        rear = temp;
    }
    count++;
}



//Dequeing the queue-removes the first element added
void dequeue()
{
    front1 = front;

    if (front1 == NULL)
    {
        printf("\n  empty queue");
        return;
    }
    else
        if (front1->ptr != NULL)//if queue has more than 1ent
        {
            front1 = front1->ptr;
            printf("\n Dequed value  %d", front->i);
            free(front);
            front = front1;//updating the front element
        }
        else //if queue has only 1 element
        {
            printf("\n Dequed value  %d", front->i);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
}


//Displaying the queue elements
void display()
{
    front1 = front;

    if ((front1 == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (front1 != rear)
    {
        printf("%d ", front1->i);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        printf("%d", front1->i);
}
