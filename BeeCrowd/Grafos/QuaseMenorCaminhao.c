#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXN 505
#define MAXM 10005
#define INF  0x3f3f3f3f

typedef struct {
    int to, w, next;
    int ban;
} Edge;

Edge E[MAXM];
int head[MAXN], ecnt;

void add_edge(int u, int v, int w) {
    E[ecnt] = (Edge){v, w, head[u], 0};
    head[u] = ecnt++;
}

typedef struct { int v, d; } Node;
Node heap[MAXN*MAXN];
int hsz;

void heap_push(Node n) {
    int i = ++hsz;
    while (i > 1 && n.d < heap[i/2].d) { heap[i] = heap[i/2]; i/=2; }
    heap[i] = n;
}
Node heap_pop() {
    Node top = heap[1], last = heap[hsz--];
    int i=1, j=2;
    while (j <= hsz) {
        if (j < hsz && heap[j+1].d < heap[j].d) j++;
        if (heap[j].d >= last.d) break;
        heap[i] = heap[j]; i = j; j *= 2;
    }
    heap[i] = last;
    return top;
}

int dist1[MAXN], dist2[MAXN];
int pred[MAXN][MAXN], pcnt[MAXN];
char vis[MAXN];

void dijkstra(int N, int S, int *dist, int ignore_ban, int store_pred) {
    memset(vis, 0, N);
    for (int i=0;i<N;i++) dist[i]=INF;
    hsz=0;
    dist[S]=0; heap_push((Node){S,0});
    while (hsz) {
        Node cur = heap_pop();
        int u = cur.v;
        if (vis[u]) continue;
        vis[u]=1;
        for (int e=head[u]; e!=-1; e=E[e].next) {
            if (ignore_ban && E[e].ban) continue;
            int v = E[e].to, nd = dist[u]+E[e].w;
            if (nd < dist[v]) {
                dist[v]=nd;
                if (store_pred) { pcnt[v]=0; pred[v][pcnt[v]++]=u; }
                heap_push((Node){v,nd});
            } else if (store_pred && nd == dist[v]) {
                pred[v][pcnt[v]++]=u;
            }
        }
    }
}

void mark_shortest(int D) {
    char qv[MAXN]={0};
    int q[MAXN], front=0, back=0;
    q[back++]=D; qv[D]=1;
    while (front<back) {
        int v = q[front++];
        for (int i=0;i<pcnt[v];i++) {
            int u = pred[v][i];
            for (int e=head[u]; e!=-1; e=E[e].next)
                if (E[e].to==v && dist1[u]+E[e].w==dist1[v])
                    E[e].ban = 1;
            if (!qv[u]) { qv[u]=1; q[back++]=u; }
        }
    }
}

int main() {
    int N,M,S,D;
    while (scanf("%d %d", &N, &M)==2 && N) {
        scanf("%d %d", &S, &D);
        memset(head,-1,sizeof(head)); ecnt=0;
        for (int i=0;i<M;i++){
            int u,v,w; scanf("%d %d %d",&u,&v,&w);
            add_edge(u,v,w); /* grafo dirigido */
        }
        memset(pcnt,0,sizeof(pcnt));
        dijkstra(N,S,dist1,0,1);       
        if (dist1[D]==INF){ puts("-1"); continue; }
        mark_shortest(D);                
        dijkstra(N,S,dist2,1,0);          
        if (dist2[D]==INF) puts("-1");
        else                printf("%d\n",dist2[D]);
    }
    return 0;
}
