#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5
void printSolution(int dist[])
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}
void initialize_single_source(int dist[], int src)
{
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
}

void relax(int u, int v, int graph[V][V], int dist[])
{
    if (dist[v] > dist[u] + graph[u][v])
        dist[v] = dist[u] + graph[u][v];
}

int extract_min(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool sptSet[V];
    initialize_single_source(dist, src);
    for (int i = 0; i < V; i++)
        sptSet[i] = false;
    for (int count = 0; count < V - 1; count++)
    {
        int u = extract_min(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX)
                relax(u, v, graph, dist);
    }
    printSolution(dist);
}

int main()
{
    int graph[V][V] = {
        {0, 10, 0, 5, 0},
        {0, 0, 1, 2, 0},
        {0, 0, 0, 0, 4},
        {0, 3, 9, 0, 2},
        {7, 0, 6, 0, 0}};
    dijkstra(graph, 0);
    return 0;
}