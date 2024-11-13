#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_VERTICES 100
int graph[MAX_VERTICES][MAX_VERTICES];
int dist[MAX_VERTICES];
bool visited[MAX_VERTICES];
void dijkstra(int vertices, int startVertex)
{
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[startVertex] = 0;
    for (int count = 0; count < vertices - 1; count++)
    {
        int minDist = INT_MAX, minIndex;
        for (int v = 0; v < vertices; v++)
        {
            if (!visited[v] && dist[v] < minDist)
            {
                minDist = dist[v];
                minIndex = v;
            }
        }
        visited[minIndex] = true;
        for (int v = 0; v < vertices; v++)
        {
            if (graph[minIndex][v] && !visited[v] && dist[minIndex] != INT_MAX &&
                dist[minIndex] + graph[minIndex][v] < dist[v])
            {
                dist[v] = dist[minIndex] + graph[minIndex][v];
            }
        }
    }
    printf("Vertex \tDistance from Source\n");
    for (int i = 0; i < vertices; i++)
        printf("%d \t%d\n", i, dist[i]);
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
        graph[dest][src] = weight; // For undirected graph
    }
    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);
    dijkstra(vertices, startVertex);
    return 0;
}