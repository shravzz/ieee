//program to implement dijkstra's algorithm using priority queues

#include <stdio.h>

struct node
{
    int dest;
    int weight;//value of the distance(edge) between the current node and its adjacent vertex
    struct node* next;
};

//  represent adjacency liat
struct list
{
    struct node *head;
};


struct graph
{
    int V;//no. of vertices
    struct list* array;
};

//  create a new adjacency list node
struct node* createNode(int dest, int weight)
{
    struct node* newNode =
            (struct node*) malloc(sizeof(struct node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

//  create a graph of V vertices
struct Graph* createGraph(int V)
{
    struct graph* g = (struct graph*) malloc(sizeof(struct graph));
    g->V = V;

    // Create an array of adjacency lists.
    g->array = (struct list*) malloc(V * sizeof(struct list));

     // Initialize head of each adjacency list  as NULL
    for (int i = 0; i < V; ++i)
        g->array[i].head = NULL;

    return g;
}




// Structure to represent a min heap node
struct MinHeapNode
{
    int  v;//represents vertex of the node
    int dist;
};

// Structure to represent a min heap
struct MinHeap
{
    int size;
    int capacity;
    int *pos;
    struct MinHeapNode **array;
};

void addEdge(struct graph* g, int source, int dest, int weight)
{
    /* Add an edge between source and dest and add a new node to adjacencyof source at the begining*/
    struct node* newNode = createNode(dest, weight);
    newNode->next = g->array[source].head;
    g->array[source].head = newNode;

    // Since graph is undirected, add an edge from dest to source also
    newNode = createNode(source, weight);
    newNode->next = g->array[dest].head;
    g->array[dest].head = newNode;
}

struct MinHeapNode* createMinHeapNode(int v, int dist)
{
    struct MinHeapNode* minHeapNode =(struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->dist = dist;
    return minHeapNode;
}

// A function to create a Min Heap
struct MinHeap* createMinHeap(int capacity)
{
    struct MinHeap* minHeap =(struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->pos = (int *)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array =(struct MinHeapNode**) malloc(capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}



void minHeapify(struct MinHeap* minHeap, int par)
{
    int smallest, left, right;
    smallest = par;
    left = 2 * par + 1;
    right = 2 * par + 2;

    if (left < minHeap->size &&
        minHeap->array[left]->dist < minHeap->array[smallest]->dist )
      smallest = left;

    if (right < minHeap->size &&
        minHeap->array[right]->dist < minHeap->array[smallest]->dist )
      smallest = right;

    if (smallest != par)
    {
        // The nodes to be swapped in min heap
        MinHeapNode *smallestNode = minHeap->array[smallest];
        MinHeapNode *parNode = minHeap->array[par];

        // Swap positions
        minHeap->pos[smallestNode->v] = par;
        minHeap->pos[parNode->v] = smallest;

        // Swap nodes
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

        minHeapify(minHeap, smallest);
    }
}

//  function to check if the given minHeap is ampty or not
int isEmpty(struct MinHeap* minHeap)
{
    return minHeap->size == 0;
}

// Standard function to extract minimum node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
    if (isEmpty(minHeap))
        return NULL;

    // Store the root node
    struct MinHeapNode* root = minHeap->array[0];

    // Replace root node with last node
    struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    // Update position of last node
    minHeap->pos[root->v] = minHeap->size-1;
    minHeap->pos[lastNode->v] = 0;

    // Reduce heap size and heapify root
    --(minHeap->size);
    minHeapify(minHeap, 0);

    return root;
}

// Function to decrease distance of a given vertex(v)
void decreaseKey(struct MinHeap* minHeap, int v, int dist)
{
    // Get the index of v in  heap array
    int i = minHeap->pos[v];

    // Get the node and update its dist value
    minHeap->array[i]->dist = dist;


    // Travel up till the complete tree is  heapified.
    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist)
    {
        // Swap this node with its parent
        minHeap->pos[minHeap->array[i]->v] = (i-1)/2;
        minHeap->pos[minHeap->array[(i-1)/2]->v] = i;

        struct MinHeapNode* t = minHeap->array[i];
        minHeap->array[i] = minHeap->array[(i-1)/2];
        minHeap->array{(i-1)/2]= t;

        // move to parent index
        i = (i - 1) / 2;
    }
}

// A  function to check if a given vertex is in min heap or not
bool isInMinHeap(struct MinHeap *minHeap, int v)
{
   if (minHeap->pos[v] < minHeap->size)//check if index  of vertex v is less than sixe of heap
     return true;

   return false;
}


void dijkstra(struct graph* g, int source)
{
    int V = g->V;
    int dist[V];


    struct MinHeap* minHeap = createMinHeap(V);

    // Initialize min heap with all vertices. dist value of all vertices
    for (int v = 0; v < V; ++v)
    {
        dist[v] = MAX;
        minHeap->array[v] = newMinHeapNode(v, dist[v]);
        minHeap->pos[v] = v;
    }

    // Initialise source vertex as 0 so that it is extracted first
    minHeap->array[source] = newMinHeapNode(source, dist[source]);
    minHeap->pos[source]   = source;
    dist[source] = 0;

    decreaseKey(minHeap, source, dist[source]);

    // Initially size of min heap is equal to V
    minHeap->size = V;


    while (!isEmpty(minHeap))
    {
        // Extract the vertex with minimum distance value
        struct MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v;

        // update the distance values of adjacent vertices of the extracted vertex
        struct node* p = graph->array[u].head;
        while (p != NULL)
        {
            int v = p->dest;

            /* If shortest distance to v is not finalized yet, and distance to v through u is less than its previously calculated distance*/
            if (isInMinHeap(minHeap, v) && dist[u] != MAX &&p->weight + dist[u] < dist[v])
            {
                dist[v] = dist[u] + p->weight;

                // update distance value in min heap also
                decreaseKey(minHeap, v, dist[v]);
            }
            p = p->next;
        }
    }

    // print the calculated shortest distances
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
    printf("%d \t\t %d\n", i, dist[i]);
}



int main()
{

    int V,source,dest,weight;
    printf("Enter no. of vertices");

    scanf(%d",&V);
    struct graph* g = createGraph(V);

    printf("Enter no. of edges");
    scanf("%d",&n);

    while(n--)
   {
       printf("\nEnter source,dest,weight of edge between them");
       scanf("%d%d%d",source,dest,weight);

       addEdge(g, source, dest, weight);
   }

    dijkstra(graph, 0);//assume source vertex is the beginning vertex

    return 0;
}

