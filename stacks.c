
//program to implement various stack functions using linked lists

#include <stdio.h>

struct node
{
    int i;
    struct node *ptr;
}*top,*top1;

int count = 0;//stores the no. of elements in stack



/* Push data into stack */
void push(int d)
{
    struct node* temp;
    if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->info = d;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
}

//pops out the last element added to stack
int pop()
{
    top1 = top;

    if (top1 == NULL)
    {

        return 0;
    }
    else
    {
        top1 = top1->ptr;

    }

     return top->i;

     free(top);
     top = top1;//assign top to  the last but one element
     count--;
}


//display elements of stack
void display()
{
    top1 = top;

    if (top1 == NULL)
    {
        printf("Stack is empty");
        return;
    }

    while (top1 != NULL)
    {
        printf("%d ", top1->i);
        top1 = top1->ptr;
    }
 }








/
