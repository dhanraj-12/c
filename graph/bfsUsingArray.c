#include <stdio.h>
#define MAX 10

void bfs (int adj [MAX][MAX], int n, int a) {

    int v [MAX] = {0};
    int queue [MAX];
    int front = 0;
    int rear = 0;

    queue[rear] = a;
    rear++;
    v[a] = 1;

    while (front < rear) {
        int a = queue[front];
        front++;
        printf("%d",a);

        for (int i = 0; i < n; i++) {
            if (adj[a][i] == 1 && v[i] != 1) {
                queue[rear] = i;
                rear++;
                v[i] = 1;
            }
        }
    }
    printf("\n");

}



int main () {

    int n,m;
    printf("Enter the number of edges and vertices : ");
    scanf("%d %d",&n,&m);

    int adj [MAX][MAX];

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("The maxtrix representation of the graph will be : \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf(" %d ",adj[i][j]);
        }
        printf("\n");
    }

    int a;
    printf("Enter the starting node of the BFS traversal : ");
    scanf("%d", &a);


    printf("The BFS traversal of the graph will be : \n");
    bfs (adj, n, a);

    

    
}