#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_VERTICES 100
int graph[MAX_VERTICES][MAX_VERTICES];
int parent[MAX_VERTICES];
int key[MAX_VERTICES];
bool mstSet[MAX_VERTICES];

void primMST(int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < vertices - 1; count++)
    {
        int minKey = INT_MAX, minIndex;
        for (int v = 0; v < vertices; v++)
        {
            if (!mstSet[v] && key[v] < minKey)
            {
                minKey = key[v];
                minIndex = v;
            }
        }
        mstSet[minIndex] = true;
        for (int v = 0; v < vertices; v++)
        {
            if (graph[minIndex][v] && !mstSet[v] && graph[minIndex][v] < key[v])
            {
                parent[v] = minIndex;
                key[v] = graph[minIndex][v];
            }
        }
    }
    printf("Edge \tWeight\n");
    for (int i = 1; i < vertices; i++)
        printf("%d - %d \t%d\n", parent[i], i, graph[parent[i]][i]);
}
int main()
{
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            graph[i][j] = 0;
    printf("Enter edges (source destination weight):\n");
    for (int i = 0; i < edges; i++)
    {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        graph[src][dest] = weight;
        graph[dest][src] = weight; 
    }
    primMST(vertices);
    return 0;
}