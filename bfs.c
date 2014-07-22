//program to implement bfs using adjacency matrix representation
#include<stdio.h>
#define MAX 20

//queue
typedef struct
{
     int data[MAX];
     int R,F;
}Q;

typedef struct
{
     struct node *next;
     int v;
}node;


int visited[MAX];
node *G[20]; //array of heads of the linked list
int n; //no. of vertices
int d[20];  //stores the distances of the vertex from source



//inserting an edge between two vertices
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
        /*since its an undirected graph,insert edge between vi and vj,vj and vi*/
        insert(vi,vj);
        insert(vj,vi);
    }
}

void enqueue(Q *P,int x)
{
    if(P->R==-1)
    {
        P->R=P->F=0;
        P->data[P->R]=x;
    }
     else
    {
        P->R=P->R+1;
        P->data[P->R]=x;
    }
}

int dequeue(Q *P)
{
    int x;
    x=P->data[P->F];
    if(P->R==P->F)
    {
       P->R=-1;
       P->F=-1;
    }
    else
    P->F=P->F+1;
    return(x);
}


int empty(Q *P)
{
    if(P->R==-1)
    return(1);
    return(0);
}

int full(Q *P)
{
    if(P->R==MAX-1)
    return(1);
    return(0);
}

void BFS(int v)
{
   int w,i,visited[MAX];
   Q q;

   node *p;
   q.R=q.F=-1; //initialise
   for(i=0;i<n;i++)
   visited[i]=0;

   enqueue(&q,v);
   printf("\nVisit\t%d",v);
   visited[v]=1;

   d[v]=0;//initialise distance of source vertex to 0

 while(!empty(&q))
 {
      v=dequeue(&q);

      //insert all unvisited,adjacent vertices of v into queue
      for(p=G[v];p!=NULL;p=p->next)
     {
         w=p->vertex;

         if(visited[w]==0)
         {
             enqueue(&q,w);
             d[w]=d[v]+1;//update the distances
             visited[w]=1;
             printf("\nvisited\t%d",w);
             printf("distance of %d from souce=%d",w,d[w]);
         }
`     }
 }
}


int main()
{
    int i,;
    inputgraph();

    printf("\nStarting Node No. : ");
    scanf("%d",&i);
    BFS(i);

    return 0;


}



