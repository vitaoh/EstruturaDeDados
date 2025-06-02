#include <stdio.h>
#include <limits.h>

#define V 10
#define INF INT_MAX

int grafo[V][V];

void inicializarGrafo()
{
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            grafo[i][j] = INF;
}

// Adicionar aresta
void adicionarAresta(int u, int v, int peso)
{
    grafo[u][v] = peso;
}

// Menor caminho de u para v (Dijkstra simplificado)
int menorCaminho(int origem, int destino)
{
    int dist[V], visitado[V] = {0};

    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[origem] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        int u = -1;
        for (int j = 0; j < V; j++)
            if (!visitado[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        if (dist[u] == INF)
            break;
        visitado[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (grafo[u][v] != INF && dist[u] + grafo[u][v] < dist[v])
            {
                dist[v] = dist[u] + grafo[u][v];
            }
        }
    }

    return dist[destino] != INF ? dist[destino] : -1;
}

// Menor tempo ida e volta de A para B
int menorTempoIdaVolta(int a, int b)
{
    int ida = menorCaminho(a, b);
    int volta = menorCaminho(b, a);
    if (ida == -1 || volta == -1)
        return -1;
    return ida + volta;
}