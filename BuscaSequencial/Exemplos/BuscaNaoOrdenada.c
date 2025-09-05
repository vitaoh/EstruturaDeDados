#include <stdio.h>
int main() {
    int X[10], i, n, achou;

    // Carregando os numeros no vetor
    // Vetor com numeros NAO ORDENADOS
    for (i = 0; i < 10; i++) {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%d", &X[i]);
    }

    // Digitando o numero a ser buscado no vetor
    printf("Digite o numero a ser buscado no vetor: ");
    scanf("%d", &n);

    // Buscando o numero digitado no vetor
    achou = 0;
    i = 0;
    while (i < 10 && achou == 0) {
        if (X[i] == n) {
            achou = 1;
        } else {
            i++;
        }
    }

    if (achou == 0) {
        printf("Numero nao encontrado no vetor\n");
    } else {
        printf("Numero encontrado na posicao %d\n", i + 1);
    }
    return 0;
}
