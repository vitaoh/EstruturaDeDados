#include <stdio.h>

int main() {
    int X[10], i, n, achou;

    // Carregando os números no vetor
    // Vetor com números ORDENADOS
    for (i = 0; i < 10; i++) {
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &X[i]);
    }

    // Digitando o número a ser buscado no vetor
    printf("Digite o número a ser buscado no vetor: ");
    scanf("%d", &n);

    // Buscando o número digitado no vetor
    achou = 0;
    i = 0;
    while (i < 10 && achou == 0 && n >= X[i]) {
        if (X[i] == n) {
            achou = 1;
        } else {
            i++;
        }
    }

    if (achou == 0) {
        printf("Número não encontrado no vetor\n");
    } else {
        printf("Número encontrado na posicao %d\n", i + 1);
    }

    return 0;
}