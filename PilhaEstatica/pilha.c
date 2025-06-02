#include "pilha.h"

void criarPilha(PILHA *p) {
    p->topo = -1;
}

bool verificarVazia(PILHA p) {
    return p.topo == -1;
}

bool verificarCheia(PILHA p) {
    return p.topo == MAX - 1;
}

bool push(PILHA *p, int valor) {
    if (verificarCheia(*p)) {
        return false;  
    }
    p->item[++p->topo] = valor;
    return true;
}

bool pop(PILHA *p, int *valor) {
    if (verificarVazia(*p)) {
        return false; 
    }
    *valor = p->item[p->topo--];
    return true;
}

int mostrarTopo(PILHA p) {
    if (verificarVazia(p)) {
        return -1; 
    }
    return p.item[p.topo];
}

void inverterPilha(PILHA *p) {
    PILHA temp;
    criarPilha(&temp);
    int valor;
    
    while (!verificarVazia(*p)) {
        pop(p, &valor);
        push(&temp, valor);
    }
    
    while (!verificarVazia(temp)) {
        pop(&temp, &valor);
        push(p, valor);
    }
}

void duplicarPilha(PILHA *p, PILHA *duplicada) {
    PILHA temp;
    criarPilha(&temp);
    
    while (!verificarVazia(*p)) {
        int valor;
        pop(p, &valor);
        push(&temp, valor);
    }

    while (!verificarVazia(temp)) {
        int valor;
        pop(&temp, &valor);
        push(duplicada, valor);
    }
    
    while (!verificarVazia(temp)) {
        int valor;
        pop(&temp, &valor);
        push(p, valor);
    }
}

int compararTamanho(PILHA p1, PILHA p2) {
    return p1.topo - p2.topo;
}