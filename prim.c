#include <stdio.h>
#include <limits.h>

#define V 5   // number of vertices

int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(int graph[V][V]) {
    int parent[V];   // stores MST
    int key[V];      // minimum edge weight
    int mstSet[V];   // visited or not

    // initialize
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;       // start from vertex 0
    parent[0] = -1;  // root

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    int **a;
    printf("enter the size of adjacent matrix:");
    scanf("%d",&n);

    a=malloc((n+1)*sizeof(int*));
    for(i=1;i<=n;i++)
    {
        a[i]=malloc((n+1)*sizeof(int));
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }


    primMST(a);
    return 0;
}
