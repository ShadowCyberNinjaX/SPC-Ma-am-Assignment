#include <stdio.h>
#define V 4

void transitiveClosure(int graph[V][V]) {
    int tc[V][V];

    // initialize reachability matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            tc[i][j] = graph[i][j];

    // Warshall's algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                tc[i][j] = tc[i][j] || (tc[i][k] && tc[k][j]);
            }
        }
    }

    // print result
    printf("Transitive Closure Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            printf("%d ", tc[i][j]);
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1}
    };

    transitiveClosure(graph);
    return 0;
}
