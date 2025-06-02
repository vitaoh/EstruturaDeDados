#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

struct pilha
{
    int item[MAX];
    int topo;
};

typedef struct pilha PILHA;

void criarPilha(PILHA *p);
bool verificarVazia(PILHA p);
bool verificarCheia(PILHA p);
bool push(PILHA *p, int valor);
bool pop(PILHA *p, int *valor);
int mostrarTopo(PILHA p);
void inverterPilha(PILHA *p);
void duplicarPilha(PILHA *p, PILHA *duplicada);
int compararTamanho(PILHA p1, PILHA p2);