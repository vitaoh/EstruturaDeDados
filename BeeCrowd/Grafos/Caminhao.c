#include <stdio.h>

int main() {
    int n, m, s;
    int grafo[105][105];
    int dist[105];
    
    while (scanf("%d %d %d", &n, &m, &s) == 3) {
        if (n == 0 && m == 0 && s == 0) break;
        
        // Inicializa grafo
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                grafo[i][j] = 0;
            }
            dist[i] = 0;
        }
        
        // Lê as pontes
        for (int i = 0; i < m; i++) {
            int a, b, p;
            scanf("%d %d %d", &a, &b, &p);
            if (grafo[a][b] < p) {
                grafo[a][b] = p;
                grafo[b][a] = p;
            }
        }
        
        // Floyd-Warshall modificado para capacidade máxima
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (grafo[i][k] > 0 && grafo[k][j] > 0) {
                        int min_cap = (grafo[i][k] < grafo[k][j]) ? grafo[i][k] : grafo[k][j];
                        if (min_cap > grafo[i][j]) {
                            grafo[i][j] = min_cap;
                        }
                    }
                }
            }
        }
        
        // Responde as consultas
        for (int i = 0; i < s; i++) {
            int sede;
            scanf("%d", &sede);
            printf("%d\n", grafo[1][sede]);
        }
    }
    
    return 0;
}