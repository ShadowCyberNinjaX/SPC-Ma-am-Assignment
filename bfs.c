#include <stdio.h>

#define V 7

int queue[V];
int front = 0, rear = -1;
int visited[V];

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

void bfs(int graph[V][V], int start) {
    enqueue(start);
    visited[start] = 1;

    while (front <= rear) {
        int u = dequeue();
        printf("%d ", u);

        for (int v = 0; v < V; v++) {
            if (graph[u][v] == 1 && visited[v] == 0) {
                enqueue(v);
                visited[v] = 1;
            }
        }
    }
}

int main() {
    int graph[V][V] = {
        {0,1,1,0,0,0,0},
        {1,0,0,1,1,0,0},
        {1,0,0,0,1,0,0},
        {0,1,0,0,0,1,0},
        {0,1,1,0,0,1,1},
        {0,0,0,1,1,0,1},
        {0,0,0,0,1,1,0}
    };

    bfs(graph, 0);
    return 0;
}
