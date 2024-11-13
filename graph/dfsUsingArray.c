#include <stdio.h>
#define MAX 10

void dfs (int adj [MAX][MAX], int v [], int n, int a) {
    v[a] = 1;
    printf(" %d ",a);

    for (int i = 0; i < n; i++) {
        if (adj[a][i] == 1 && v[i] == 0) {
            dfs (adj, v, n, i);
        }
    }

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
    printf("Enter the starting node of the DFS traversal : ");
    scanf("%d", &a);


    printf("The DFS traversal of the graph will be : \n");
    int v [MAX] = {0};
    dfs (adj, v, n, a);

    

    
}