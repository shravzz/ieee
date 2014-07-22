//program to implement dfs using stacks
#include<stdio.h>
#define MAX 20

typedef struct
{
   int data[MAX];
   int top;
}stack;

typedef struct node
{
    struct node *next;
    int vertex;
}node;


int visited[MAX];
node *G[20];   //heads of the linked list
int n;        // no of nodes


void insert(int vi,int vj)
{
     node *p,*q;

     q=(node *)malloc(sizeof(node));
     q->vertex=vj;
     q->next=NULL;

     //insert the node in the linked list for the vertex no. vi
     if(G[vi]==NULL)
     G[vi]=q;
     else
    {
          // go to the end of linked list
          p=G[vi];
          while(p->next!=NULL)
          p=p->next;

          p->next=q;
     }
}

void inputgraph()
{
    int i,vi,vj,no_of_edges;
    printf("\nEnter no. of vertices :");
    scanf("%d",&n);

    //initialise heads with NULL
     for(i=0;i<n;i++)
     G[i]=NULL;

    //read edges and insert them in G[]
    printf("\nEnter no of edges :");
    scanf("%d",&no_of_edges);
    for(i=0;i<no_of_edges;i++)
    {
        printf("\nEnter an edge (u,v)  :");
        scanf("%d%d",&vi,&vj);
        insert(vi,vj);
        insert(vj,vi);
    }
}

void push(stack *s,int i)
{
       s->top=s->top+1;
       s->data[s->top]=i;

}
int pop(stack *s)
{
    return(s->data[s->top]);
}

void DFS(int i)
{
    stack *s;
    s->top=-1;//initialise top of the stack

    int t,w;
    node *p;
    p=G[i];

    push(&s,i);//push the source element in stack
    visited[i]=1;

    while(s!=null)
    {
        t=pop(&s);//pop the last node inserted in stack
        printf("\nvisited\t%d",t);

        for(p=G[t];p!=null;p=p->next)
        {
              w=p->vertex;

              if(visited[w]==0)
              {
                  push(&s,w);
                  visited[w]=1;


               }

        }


    }
}
int main()
{
    int i;
    inputgraph();
    printf("\nStarting Node No. : ");
    scanf("%d",&i);
    DFS(i);

    return 0;
}



