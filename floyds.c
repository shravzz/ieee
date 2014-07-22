
//program to detect a loop in linked list

#include<stdio.h>

struct node
{
    int d;
    struct node* next;
};

void push(struct node** head, int d)
{

     struct node* new_node =(struct node*) malloc(sizeof(struct node));


      new_node->d  = d;


     new_node->next = (*head);
      (*head)    = new_node;
}

int detectloop(struct node *list)
{
      struct node  *slow = list, *fast = list;

       while(slow && fast &&fast->next )//slow shifts by one elemnent and fast shifts by 2 elements
      {
           slow = slow->next;
           fast  = fast->next->next;
           if (slow== fast)
          {
                 printf("Found Loop");
                 return 1;
          }
       }
      return 0;
}

int main()
{
     int n,i;
     struct node* head = NULL;

     printf("%d",Enter the no. of elements);
     scanf("%d",&n);
     printf("Enter the elements");
     while(n--)
     {
         scanf("%d",i);
         push(&head,i);
     }



     /* Create a loop for testing */
     head->next->next->next->nesxt = head;

     int t=detectloop(head);
     if(t==1)
        printf("loop detected");

     else
         printf("loop not detected");

     getchar();
     return 0;
}

