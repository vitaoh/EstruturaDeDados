#include <stdio.h>
#include <string.h>

int isLetter(char c) {
    if (c >= 'A' && c <= 'Z') return 1;
    if (c >= 'a' && c <= 'z') return 1;
    return 0;
}

int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

int isValidIdentifier(char *id) {
    int len = strlen(id);
    if (len < 1 || len > 6) {
        return 0;
    }
    if (!isLetter(id[0])) {
        return 0;
    }
    for (int i = 1; i < len; i++) {
        if (!isLetter(id[i]) && !isDigit(id[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char id[100];
    printf("Digite o identificador: ");
    scanf("%99s", id);
    if (isValidIdentifier(id)) {
        printf("Identificador válido\n");
    } else {
        printf("Identificador inválido\n");
    }
    return 0;
}
