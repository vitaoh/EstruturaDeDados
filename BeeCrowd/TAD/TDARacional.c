#include <stdio.h>

int verDiv(int x, int y)
{
    if(x < 0) x = x * -1;
    if(y < 0) y = y * -1;
    int menor = x < y ? x : y;

    for (int i = menor; i > 1; i--)
    {
        if (x % i == 0 && y % i == 0)
            return i;
    }
    return 1;
}

int main()
{
    int qtdOperacoes;
    scanf("%d", &qtdOperacoes);

    int matrizNum[qtdOperacoes][4];
    char matrizOpr[qtdOperacoes];

    for (int i = 0; i < qtdOperacoes; i++)
    {
        scanf("%d / %d %c %d / %d", &matrizNum[i][0], &matrizNum[i][1], &matrizOpr[i], &matrizNum[i][2], &matrizNum[i][3]);
    }

    for (int i = 0; i < qtdOperacoes; i++)
    {
        int num_res, den_res;

        switch (matrizOpr[i])
        {
            case '+':
                num_res = matrizNum[i][0] * matrizNum[i][3] + matrizNum[i][2] * matrizNum[i][1];
                den_res = matrizNum[i][1] * matrizNum[i][3];
                break;
            case '-':
                num_res = matrizNum[i][0] * matrizNum[i][3] - matrizNum[i][2] * matrizNum[i][1];
                den_res = matrizNum[i][1] * matrizNum[i][3];
                break;
            case '*':
                num_res = matrizNum[i][0] * matrizNum[i][2];
                den_res = matrizNum[i][1] * matrizNum[i][3];
                break;
            case '/':
                num_res = matrizNum[i][0] * matrizNum[i][3];
                den_res = matrizNum[i][1] * matrizNum[i][2];
                break;
            default:
                num_res = 0;
                den_res = 1;
                break;
        }

        int div = verDiv(num_res, den_res);

        printf("%d/%d = %d/%d\n", num_res, den_res, num_res / div, den_res / div);
    }

    return 0;
}
