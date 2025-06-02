#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int chegada;
    int condicao;
    int tempo_limite;
} Paciente;

int main() {
    int n;
    scanf("%d", &n);
    
    if (n == 0) {
        printf("0\n");
        return 0;
    }
    
    Paciente *pacientes = (Paciente*)malloc(n * sizeof(Paciente));
    
    for (int i = 0; i < n; i++) {
        int h, m, c;
        scanf("%d %d %d", &h, &m, &c);
        pacientes[i].chegada = h * 60 + m;
        pacientes[i].condicao = c;
        pacientes[i].tempo_limite = (c <= 720) ? c : 720;
    }
    
    int tempo_atual = pacientes[0].chegada;
    int atendidos = 0;
    int criticos = 0;
    
    for (int i = 0; i < n; i++) {
        if (pacientes[i].chegada > tempo_atual) {
            tempo_atual = pacientes[i].chegada;
        }
        
        int tempo_espera = tempo_atual - pacientes[i].chegada;
        
        if (tempo_espera >= pacientes[i].tempo_limite) {
            criticos++;
        }
        
        tempo_atual += 1;
        atendidos++;
    }
    
    printf("%d\n", criticos);
    
    free(pacientes);
    return 0;
}