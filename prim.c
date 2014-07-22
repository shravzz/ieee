
//function to implement prim's algorithm

void Prim(struct graph* g)
{
    int V = graph->V;// no. of vertices
    int parent[V];   // Array to store constructed MST
    int key[V//stores key values of vertices
    int dist;//stores minimum distance to traverse entire graph


    struct MinHeap* minHeap = createMinHeap(V);

    // Initialize min heap with all vertices. Key value of all vertices (except 0th vertex) is initially infinite
    for (int v = 1; v < V; ++v)
    {
        parent[v] = -1;
        dist[v] = INT_MAX;
        minHeap->array[v] = newMinHeapNode(v, key[v]);//creates a new minheap node
        minHeap->pos[v] = v;
    }

    // Make key value of 0th vertex as 0 so that it is extracted first
    key[0] = 0;
    minHeap->array[0] = newMinHeapNode(0, key[0]);
    minHeap->pos[0]   = 0;
    dist=0;

    // Initially size of min heap is equal to V
    minHeap->size = V;

    // In the followin loop, min heap contains all node not yet added to MST.
    while (!isEmpty(minHeap))
    {
        // Extract the vertex with minimum dist value
        struct MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v; // Store the extracted vertex number
        dist=dist+key[u];//compute min. distance of MST

        // update the dist values of vertices adjacent to the vertex extracted
        struct node* p = g->array[u].head;
        while (p != NULL)
        {
            int v = p->dest;

            /* If v is not yet included in MST and weight of u-v is less than key value of v, then update key value and
             parent of v*/
            if (isInMinHeap(minHeap, v) && p->weight < key[v])
            {
                key[v] = p->weight;
                parent[v] = u; //construct MST(i.e the extracted vertex with min key value)
                decreaseKey(minHeap, v, key[v]); //updates the key of vertex v in the minheap
            }
            p = p->next;
        }
    }

    // print edges of MST and minimum distance after finding MST
}

