#include <stdio.h>

void cadastrar(int v[], int n)
{
    printf("\nDigite os %i números inteiros: ", n);
    for (int i = 0; i < n; i++)
        scanf("%i", &v[i]);
}

void bubbleSort(int v[], int n)
{
    int aux;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (v[j] > v[j + 1])
            {
                aux = v[j + 1];
                v[j + 1] = v[j];
                v[j] = aux;
            }
}

void insertionSort(int v[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int chave = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > chave)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

int buscaSequencial(int v[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (v[i] == x)
            return i;
    }
    return -1;
}

int buscaBinaria(int v[], int n, int x)
{
    int ini = 0, fim = n - 1;
    while (ini <= fim)
    {
        int meio = (ini + fim) / 2;
        if (v[meio] == x)
            return meio;
        else if (v[meio] < x)
            ini = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}

int main()
{
    int v[5], op, x, res;
    cadastrar(v, 5);

    printf("\nEscolha o método de ordenação:\n 1 | Bubble Sort\n 2 | Insertion Sort\n R: ");
    scanf("%i", &op);
    if (op == 1)
        bubbleSort(v, 5);
    else
        insertionSort(v, 5);

    printf("\nVetor ordenado: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", v[i]);

    printf("\nDigite o número para buscar: ");
    scanf("%d", &x);

    printf("\nBusca sequencial...\n");
    res = buscaSequencial(v, 5, x);
    if (res != -1)
        printf("Encontrado na posição %d\n", res);
    else
        printf("Não encontrado\n");

    printf("\nBusca binária...\n");
    res = buscaBinaria(v, 5, x);
    if (res != -1)
        printf("Encontrado na posição %d\n", res);
    else
        printf("Não encontrado\n");

    return 0;
}
