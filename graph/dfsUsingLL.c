#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node
{
    int vertex;
    struct Node *next;
};
struct Graph
{
    int numVertices;
    struct Node **adjLists;
};
struct Node *createNode(int v)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct
                                                        Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct
                                                        Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node **)malloc(vertices * sizeof(struct
                                                               Node *));
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;
    return graph;
}
void addEdge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}
void DFSUtil(struct Graph *graph, int vertex, bool *visited)
{
    visited[vertex] = true;
    printf("%d ", vertex);
    struct Node *temp = graph->adjLists[vertex];
    while (temp)
    {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex])
        {
            DFSUtil(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}
void DFS(struct Graph *graph, int startVertex)
{
    bool *visited = (bool *)malloc(graph->numVertices *
                                   sizeof(bool));
    for (int i = 0; i < graph->numVertices; i++)
        visited[i] = false;
    DFSUtil(graph, startVertex, visited);
    free(visited);
}
int main()
{
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    struct Graph *graph = createGraph(vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++)
    {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);
    printf("DFS starting from vertex %d: ", startVertex);
    DFS(graph, startVertex);
    for (int i = 0; i < graph->numVertices; i++)
    {
        struct Node *temp = graph->adjLists[i];
        while (temp)
        {
            struct Node *toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);
    return 0;
}