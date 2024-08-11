#include <stdio.h>

#define MAX 10
#define INF 999999

void print(int graph[][MAX], int vertices) {
    printf("Graph Adjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int minDist(int dist[], int sptSet[], int vertices) {
    int min = INF, minIndex;

    for (int v = 0; v < vertices; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void printShortestPath(int dist[], int vertices) {
    printf("\nShortest Path (Dijkstra's Algorithm):\n");
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < vertices; i++)
        printf("%d \t %d\n", i, dist[i]);
}

void dijkstra(int graph[][MAX], int src, int vertices) {
    int dist[MAX];
    int sptSet[MAX];

    for (int i = 0; i < vertices; i++) {
        dist[i] = INF;
        sptSet[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minDist(dist, sptSet, vertices);

        sptSet[u] = 1;

        for (int v = 0; v < vertices; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printShortestPath(dist, vertices);
}

void primMST(int graph[][MAX], int vertices) {
    int parent[MAX];
    int key[MAX];
    int mstSet[MAX];

    for (int i = 0; i < vertices; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minDist(key, mstSet, vertices);

        mstSet[u] = 1;

        for (int v = 0; v < vertices; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    printf("\nMinimum Spanning Tree (Prim's Algorithm):\n");
    for (int i = 1; i < vertices; i++)
        printf("Edge: %d - %d\n", parent[i], i);
}

int main() {
    int vertices; // Number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[MAX][MAX];

    // Input the graph from the user
    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            scanf("%d", &graph[i][j]);

    // Print the graph
    print(graph, vertices);

    // Find the shortest path using Dijkstra's algorithm
    dijkstra(graph, 0, vertices);

    // Find the minimum spanning tree using Prim's algorithm
    primMST(graph, vertices);

    return 0;
}
