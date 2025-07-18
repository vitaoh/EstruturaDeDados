#include <stdio.h>
#include <string.h>

int stacks[3][101];
int memo[101][101][101];
int n;

int solve(int a, int b, int c) {
    if (a == n && b == n && c == n) {
        return 1;
    }
    
    if (memo[a][b][c] != -1) {
        return memo[a][b][c];
    }
    
    if (a < n && stacks[0][a] % 3 == 0) {
        if (solve(a + 1, b, c)) {
            return memo[a][b][c] = 1;
        }
    }
    
    if (b < n && stacks[1][b] % 3 == 0) {
        if (solve(a, b + 1, c)) {
            return memo[a][b][c] = 1;
        }
    }
    
    if (c < n && stacks[2][c] % 3 == 0) {
        if (solve(a, b, c + 1)) {
            return memo[a][b][c] = 1;
        }
    }
    
    if (a < n && b < n && (stacks[0][a] + stacks[1][b]) % 3 == 0) {
        if (solve(a + 1, b + 1, c)) {
            return memo[a][b][c] = 1;
        }
    }
    
    if (a < n && c < n && (stacks[0][a] + stacks[2][c]) % 3 == 0) {
        if (solve(a + 1, b, c + 1)) {
            return memo[a][b][c] = 1;
        }
    }
    
    if (b < n && c < n && (stacks[1][b] + stacks[2][c]) % 3 == 0) {
        if (solve(a, b + 1, c + 1)) {
            return memo[a][b][c] = 1;
        }
    }
    
    if (a < n && b < n && c < n && (stacks[0][a] + stacks[1][b] + stacks[2][c]) % 3 == 0) {
        if (solve(a + 1, b + 1, c + 1)) {
            return memo[a][b][c] = 1;
        }
    }
    
    return memo[a][b][c] = 0;
}

int main() {
    while (scanf("%d", &n) && n != 0) {

        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &stacks[0][i], &stacks[1][i], &stacks[2][i]);
        }
        
        memset(memo, -1, sizeof(memo));
        
        printf("%d\n", solve(0, 0, 0));
    }
    
    return 0;
}
