#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AERONAVES 1000

typedef struct
{
    char aeronaves[MAX_AERONAVES][10];
    int inicio;
    int fim;
} Fila;

void inicializarFila(Fila *f)
{
    f->inicio = 0;
    f->fim = 0;
}

int filaVazia(Fila *f)
{
    return f->inicio == f->fim;
}

void enfileirar(Fila *f, const char *aeronave)
{
    if (f->fim < MAX_AERONAVES)
    {
        strcpy(f->aeronaves[f->fim], aeronave);
        f->fim++;
    }
}

void desenfileirar(Fila *f, char *aeronave)
{
    if (!filaVazia(f))
    {
        strcpy(aeronave, f->aeronaves[f->inicio]);
        f->inicio++;
    }
    else
    {
        aeronave[0] = '\0';
    }
}

int main()
{
    Fila oeste, norte, sul, leste;
    inicializarFila(&oeste);
    inicializarFila(&norte);
    inicializarFila(&sul);
    inicializarFila(&leste);

    int ponto_cardinal = 0;
    char aeronave[10];

    while (1)
    {
        scanf("%s", aeronave);

        if (aeronave[0] == '-' || (aeronave[0] >= '0' && aeronave[0] <= '9'))
        {
            ponto_cardinal = atoi(aeronave);
            if (ponto_cardinal == 0)
                break;
            continue;
        }

        switch (ponto_cardinal)
        {
        case -1:
            enfileirar(&oeste, aeronave);
            break;
        case -3:
            enfileirar(&norte, aeronave);
            break;
        case -2:
            enfileirar(&sul, aeronave);
            break;
        case -4:
            enfileirar(&leste, aeronave);
            break;
        }
    }

    int primeiro = 1;

    while (!filaVazia(&oeste) || !filaVazia(&norte) || !filaVazia(&sul) || !filaVazia(&leste))
    {
        if (!filaVazia(&oeste))
        {
            if (!primeiro)
                printf(" ");
            desenfileirar(&oeste, aeronave);
            printf("%s", aeronave);
            primeiro = 0;
        }

        if (!filaVazia(&norte))
        {
            if (!primeiro)
                printf(" ");
            desenfileirar(&norte, aeronave);
            printf("%s", aeronave);
            primeiro = 0;
        }

        if (!filaVazia(&sul))
        {
            if (!primeiro)
                printf(" ");
            desenfileirar(&sul, aeronave);
            printf("%s", aeronave);
            primeiro = 0;
        }

        if (!filaVazia(&leste))
        {
            if (!primeiro)
                printf(" ");
            desenfileirar(&leste, aeronave);
            printf("%s", aeronave);
            primeiro = 0;
        }
    }

    printf("\n");

    return 0;
}