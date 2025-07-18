#include <stdio.h>
#include <stdlib.h>

#define MAX_ID 100001

int main() {
    int N, M;
    int *fila, id, i;
    char *saiu; 

    scanf("%d", &N);

    fila = (int*)malloc(N * sizeof(int));
    saiu = (char*)calloc(MAX_ID, sizeof(char)); 

    for (i = 0; i < N; i++) {
        scanf("%d", &fila[i]);
    }

    scanf("%d", &M);

    for (i = 0; i < M; i++) {
        scanf("%d", &id);
        saiu[id] = 1;
    }

    int primeiro = 1;
    for (i = 0; i < N; i++) {
        if (!saiu[fila[i]]) {
            if (!primeiro) printf(" ");
            printf("%d", fila[i]);
            primeiro = 0;
        }
    }
    printf("\n");

    free(fila);
    free(saiu);
    return 0;
}