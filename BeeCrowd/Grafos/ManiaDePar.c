#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAXN 10005
#define MAXM 100005
#define INF 0x3f3f3f3f

typedef struct {
    int to, weight, next;
} Edge;

typedef struct {
    int vertex, dist, parity;
} Node;

Edge edges[MAXM];
int head[MAXN], edge_count;
int dist[MAXN][2];

Node heap[MAXN * 4];
int heap_size;

void push(int v, int d, int p) {
    int i = heap_size++;
    heap[i] = (Node){v, d, p};
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[i].dist < heap[parent].dist) {
            Node temp = heap[i];
            heap[i] = heap[parent];
            heap[parent] = temp;
            i = parent;
        } else break;
    }
}

Node pop() {
    Node root = heap[0];
    heap[0] = heap[--heap_size];
    int i = 0;
    while (1) {
        int left = 2 * i + 1, right = 2 * i + 2, smallest = i;
        if (left < heap_size && heap[left].dist < heap[smallest].dist) smallest = left;
        if (right < heap_size && heap[right].dist < heap[smallest].dist) smallest = right;
        if (smallest != i) {
            Node temp = heap[i];
            heap[i] = heap[smallest];
            heap[smallest] = temp;
            i = smallest;
        } else break;
    }
    return root;
}

void addEdge(int u, int v, int w) {
    edges[edge_count] = (Edge){v, w, head[u]};
    head[u] = edge_count++;
}

int dijkstra(int n, int start, int end) {
    for (int i = 1; i <= n; i++) {
        dist[i][0] = dist[i][1] = INF;
    }
    
    dist[start][0] = 0;
    heap_size = 0;
    push(start, 0, 0);
    
    while (heap_size > 0) {
        Node current = pop();
        int u = current.vertex;
        int d = current.dist;
        int parity = current.parity;
        
        if (d > dist[u][parity]) continue;
        
        for (int e = head[u]; e != -1; e = edges[e].next) {
            int v = edges[e].to;
            int w = edges[e].weight;
            int new_parity = 1 - parity;
            int new_dist = d + w;
            
            if (new_dist < dist[v][new_parity]) {
                dist[v][new_parity] = new_dist;
                push(v, new_dist, new_parity);
            }
        }
    }
    
    return dist[end][0] == INF ? -1 : dist[end][0];
}

int main() {
    int C, V;
    scanf("%d %d", &C, &V);
    
    memset(head, -1, sizeof(head));
    edge_count = 0;
    
    for (int i = 0; i < V; i++) {
        int c1, c2, g;
        scanf("%d %d %d", &c1, &c2, &g);
        addEdge(c1, c2, g);
        addEdge(c2, c1, g);
    }
    
    printf("%d\n", dijkstra(C, 1, C));
    
    return 0;
}