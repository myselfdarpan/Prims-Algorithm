#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 5

int minkey(int key[], bool mstset[])
{
    int min = INT_MAX, min_index;

    for(int v=0; v < V; v++)
    {
        if(mstset[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[V][V])
{
    printf("Edge \tWeight\n");
    for(int i=1; i < V; i++)
    {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

void prims(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstset[V];

    for(int i=0; i<V; i++)
    {
        key[i]= INT_MAX;
        mstset[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int count = 0; count < V-1; count++)
    {
        int u = minkey(key, mstset);
        mstset[u] = true;

        for(int v=0; v < V; v++)
        {
            if(graph[u][v] && mstset[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
        
    }
    printMST(parent, graph);
}

int main()
{
   int graph[V][V] = {{0, 2, 999, 6, 999},
                      {2, 0, 3, 8, 5},
                      {999, 3, 0, 999, 7},
                      {6, 8, 999, 0, 9},
                      {999, 5, 7, 9, 0}};

    prims(graph);
    return 0;
}
