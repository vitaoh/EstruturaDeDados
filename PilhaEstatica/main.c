#include <stdio.h>
#include "pilha.h"

int main() {
    PILHA p;
    PILHA p2;
    
    // Cria a pilha p e p2
    criarPilha(&p);
    criarPilha(&p2);
    
    // Empilhar valores
    push(&p, 10);
    push(&p, 20);
    push(&p, 30);
    
    printf("Topo da pilha p: %d\n", mostrarTopo(p));  // Saída esperada: 30
    
    // Duplicar a pilha p em p2
    duplicarPilha(&p, &p2);
    
    printf("Topo da pilha p2 (duplicada): %d\n", mostrarTopo(p2));  // Saída esperada: 30
    
    // Comparar tamanhos
    printf("Comparando pilha p e p2: %d\n", compararTamanho(p, p2));  // Saída esperada: 0 (mesmo tamanho)
    
    // Inverter a pilha p
    inverterPilha(&p);
    printf("Topo da pilha p após inverter: %d\n", mostrarTopo(p));  // Saída esperada: 10

    return 0;
}