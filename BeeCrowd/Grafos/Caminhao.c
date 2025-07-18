#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 20005
#define MAXM 100005
#define LOGN 15

typedef struct { int u, v, w; } Edge;
Edge edges[MAXM];
int parent[MAXN], rnk[MAXN];
int head[MAXN], to[MAXN*2], nxt[MAXN*2], wgt[MAXN*2], ecnt;

void make_set(int n){ for(int i=1;i<=n;i++){ parent[i]=i; rnk[i]=0; } }
int find(int x){ return parent[x]==x? x : (parent[x]=find(parent[x])); }
void unite(int a,int b){ a=find(a); b=find(b);
    if(a==b) return;
    if(rnk[a]<rnk[b]) parent[a]=b;
    else if(rnk[a]>rnk[b]) parent[b]=a;
    else { parent[b]=a; rnk[a]++; }
}

void add_edge(int u,int v,int w){
    to[ecnt]=v; wgt[ecnt]=w; nxt[ecnt]=head[u]; head[u]=ecnt++;
}

int up[MAXN][LOGN], mx[MAXN][LOGN], depth[MAXN];

void dfs(int u,int p,int pw){
    up[u][0]=p; mx[u][0]=pw;
    for(int k=1;k<LOGN;k++){
        int anc=up[u][k-1];
        up[u][k]= up[anc][k-1];
        mx[u][k]= (anc? (mx[u][k-1]<mx[anc][k-1]? mx[u][k-1]:mx[anc][k-1]) : mx[u][k-1]);
    }
    for(int e=head[u]; e!=-1; e=nxt[e]){
        int v=to[e], w=wgt[e];
        if(v==p) continue;
        depth[v]=depth[u]+1;
        dfs(v,u,w);
    }
}

int query(int a,int b){
    if(a==b) return 1<<30;
    int ans=1<<30;
    if(depth[a]<depth[b]){ int t=a;a=b;b=t; }
    int diff=depth[a]-depth[b];
    for(int k=LOGN-1;k>=0;k--)
        if(diff&(1<<k)){
            ans = ans<mx[a][k]? ans:mx[a][k];
            a=up[a][k];
        }
    if(a==b) return ans;
    for(int k=LOGN-1;k>=0;k--)
        if(up[a][k]!=up[b][k]){
            ans = ans<mx[a][k]? ans:mx[a][k];
            ans = ans<mx[b][k]? ans:mx[b][k];
            a=up[a][k]; b=up[b][k];
        }
    ans = ans<mx[a][0]? ans:mx[a][0];
    ans = ans<mx[b][0]? ans:mx[b][0];
    return ans;
}

int cmp(const void* a,const void* b){ return ((Edge*)b)->w - ((Edge*)a)->w; }

int main(){
    int N,M,S;
    while(scanf("%d %d %d",&N,&M,&S)==3){
        for(int i=0;i<M;i++) scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].w);
        qsort(edges,M,sizeof(Edge),cmp);
        make_set(N);
        memset(head,-1,sizeof(head)); ecnt=0;
        int used=0;
        for(int i=0;i<M && used<N-1;i++){
            int u=edges[i].u, v=edges[i].v, w=edges[i].w;
            if(find(u)!=find(v)){
                unite(u,v); used++;
                add_edge(u,v,w);
                add_edge(v,u,w);
            }
        }
        memset(up,0,sizeof(up));
        depth[1]=0;
        dfs(1,0,1<<30);
        while(S--){
            int l,h; scanf("%d %d",&l,&h);
            printf("%d\n", query(l,h));
        }
    }
    return 0;
}