#include <stdio.h>

#define MAX_SIZE 1001

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void push(Stack *s, char c) {
    s->data[++s->top] = c;
}

char pop(Stack *s) {
    return s->data[s->top--];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int main() {
    int n;
    scanf("%d", &n);
    
    while (n--) {
        char linha[MAX_SIZE];
        scanf("%s", linha);
        
        Stack pilha;
        pilha.top = -1;
        
        int diamantes = 0;
        int i = 0;
        
        while (linha[i] != '\0') {
            if (linha[i] == '<') {
                push(&pilha, '<');
            } else if (linha[i] == '>' && !isEmpty(&pilha)) {
                pop(&pilha);
                diamantes++;
            }
            i++;
        }
        
        printf("%d\n", diamantes);
    }
    
    return 0;
}