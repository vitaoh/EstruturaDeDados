#include <stdio.h>
#include <string.h>

int minimos[1000000];
int p = -1;

int main() {
    int n, v;
    char operacao[5];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", operacao);

        if (strcmp(operacao, "PUSH") == 0) {
            scanf("%d", &v);

            if (p == -1) {
                minimos[++p] = v;
            } else {
                int minimo = (minimos[p] < v) ? minimos[p] : v;
                minimos[++p] = minimo;
            }
        }
        else if (strcmp(operacao, "POP") == 0) {
            if (p == -1) {
                printf("EMPTY\n");
            } else {
                p--;
            }
        }
        else if (strcmp(operacao, "MIN") == 0) {
            if (p == -1) {
                printf("EMPTY\n");
            } else {
                printf("%d\n", minimos[p]);
            }
        }
    }

    return 0;
}