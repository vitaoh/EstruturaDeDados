// Faça um programa que cadastre 15 números ordenados, por exemplo {1, 5, 9, 13, 17,
// 21, 25, 29, 33, 37, 41, 45, 49, 53, 57}. Verifique se um número digitado pelo usuário
// está no vetor.
// a) usando busca sequencial;
// b) usando busca binária

#include <stdio.h>

#define T 15

int buscaSequencial(int vetor[], int n, int valor)
{
    for (int i = 0; i < n; i++)
    {
        if (vetor[i] == valor)
        {
            return i;
        }
    }
    return -1;
}

int buscaBinaria(int vetor[], int n, int valor)
{
    int inicio = 0, fim = n - 1, meio;

    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        if (vetor[meio] == valor)
        {
            return meio;
        }
        else if (vetor[meio] < valor)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }

    return -1;
}

int main()
{
    int vetor[T] = {1, 5, 9, 13, 17, 21, 25, 29, 33,
                    37, 41, 45, 49, 53, 57};

    int num, pos;

    printf("Digite um numero para buscar: ");
    scanf("%d", &num);

    pos = buscaSequencial(vetor, T, num);
    if (pos != -1)
    {
        printf("Busca sequencial: numero %d encontrado na posicao %d\n", num, pos);
    }
    else
    {
        printf("Busca sequencial: numero %d NAO encontrado\n", num);
    }

    pos = buscaBinaria(vetor, T, num);
    if (pos != -1)
    {
        printf("Busca binaria: numero %d encontrado na posicao %d\n", num, pos);
    }
    else
    {
        printf("Busca binaria: numero %d NAO encontrado\n", num);
    }

    return 0;
}