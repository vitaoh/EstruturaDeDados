#include <stdio.h>

int main() {
    int N = 1;
    
    while (0 < N && N <= 25) {
        scanf("%d", &N);
        if (N == 0) {
            printf("0\n");
            continue;
        }
        
        int chegada[N], critico[N];
        int h, m, c;

        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &h, &m, &c);
            chegada[i] = (h - 7) * 60 + m;
            critico[i] = c;
        }
        
        int tempo_atual = 0;
        int cont_criticos = 0;

        for (int i = 0; i < N; i++) {
            if (tempo_atual < chegada[i]) {
                tempo_atual = chegada[i];
            }
            int espera = tempo_atual - chegada[i];
            if (espera >= critico[i]) {
                cont_criticos++;
            }
            tempo_atual += 30;
        }

        printf("%d\n", cont_criticos);
    }
    
    return 0;
}
