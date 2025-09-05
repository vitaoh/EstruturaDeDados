#include <stdio.h>
#include <stdlib.h>

void main()
{
    int X[10], np, i, inicio, fim, meio, achou;
    system("cls"); // Equivalente a clrscr() para limpar a tela
    // carregando os numeros no vetor - ORDENADOS
    for(i=0;i<=9;i++)
    {
        printf("Digite o %d° numero: ", i+1);
        scanf("%d", &X[i]);
    }
    // digitando o numero a ser buscado no vetor
    printf("Digite o numero a ser buscado no vetor: ");
    scanf("%d", &np);
    // buscando o numero digitado no vetor
    achou = 0;
    inicio = 0;
    fim = 9;
    meio = (inicio+fim)/2;
    while (inicio <= fim && achou == 0)
    {
        if (X[meio] == np)
            achou = 1;
        else
        {
            if (np < X[meio])
                fim = meio-1;
            else
                inicio = meio+1;
        }
        meio = (inicio+fim)/2;
    }
    if (achou == 0)
        printf("Numero nao encontrado no vetor");
    else
        printf("Numero encontrado na posicao %d", meio+1);
    
    // Substitui getch()
    printf("\nPressione Enter para sair...");
    getchar(); // Espera por um caractere pendente no buffer
    getchar(); // Espera a tecla Enter
}