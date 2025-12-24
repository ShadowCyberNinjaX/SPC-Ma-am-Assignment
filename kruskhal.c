#include <stdio.h>
#include <stdlib.h>

#define INF 99999

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void unionSet(int parent[], int x, int y) {
    parent[find(parent, x)] = find(parent, y);
}

void sortEdges(int u[], int v[], int w[], int E) {
    int temp;
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (w[j] > w[j + 1]) {
                temp = w[j]; w[j] = w[j + 1]; w[j + 1] = temp;
                temp = u[j]; u[j] = u[j + 1]; u[j + 1] = temp;
                temp = v[j]; v[j] = v[j + 1]; v[j + 1] = temp;
            }
        }
    }
}


void kruskal(int **adj, int V) {
    int maxEdges = V * V;

    int *u = (int *)malloc(maxEdges * sizeof(int));
    int *v = (int *)malloc(maxEdges * sizeof(int));
    int *w = (int *)malloc(maxEdges * sizeof(int));

    int E = 0;

    
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (adj[i][j] != 0 && adj[i][j] != INF) {
                u[E] = i;
                v[E] = j;
                w[E] = adj[i][j];
                E++;
            }
        }
    }

    sortEdges(u, v, w, E);

    int *parent = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++)
        parent[i] = i;

    int edges = 0, cost = 0;

    printf("\nEdges in Minimum Spanning Tree:\n");

    for (int i = 0; i < E && edges < V - 1; i++) {
        if (find(parent, u[i]) != find(parent, v[i])) {
            printf("%d -- %d  weight = %d\n", u[i], v[i], w[i]);
            cost += w[i];
            unionSet(parent, u[i], v[i]);
            edges++;
        }
    }

    printf("Minimum Cost = %d\n", cost);

    free(u);
    free(v);
    free(w);
    free(parent);
}

int main() {
    int V;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int **adj = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        adj[i] = (int *)malloc(V * sizeof(int));

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < V; i++) 
    {
        for (int j = 0; j < V; j++) 
        {
            scanf("%d", &adj[i][j]);
        }
    }

    kruskal(adj, V);

    for (int i = 0; i < V; i++)
        free(adj[i]);
    free(adj);

    return 0;
}
