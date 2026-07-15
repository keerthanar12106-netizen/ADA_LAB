#include <stdio.h>
int n, m, p[10], w[10];

int max(int a, int b) {
    return (a > b) ? a : b;
}
void knapsack_DP() {
    int v[10][10], i, j;
    for (i = 0; i <= n; i++)
        for (j = 0; j <= m; j++)
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else if (j < w[i])
                v[i][j] = v[i - 1][j];
            else
                v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i]] + p[i]);
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++)
            printf("%d ", v[i][j]);
        printf("\n");
    }
    printf("Items included in the knapsack:\n");
    while (n > 0) {
        if (v[n][m] != v[n - 1][m]) {
            printf("Item %d\n", n);
            m = m - w[n];
        }
        n--;
    }
}

int main() {
    int i;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weights of items: ");
    for (i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    printf("Enter prices of items: ");
    for (i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    printf("Enter capacity of knapsack: ");
    scanf("%d", &m);
    knapsack_DP();
    return 0;
}
