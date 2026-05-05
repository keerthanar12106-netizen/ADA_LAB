#include <stdio.h>

int cost[10][10], n;

void kruskal() {
    int par[10];
    int a = 0, b = 0, u = 0, v = 0, min, mincost = 0, ne = 0;

    /* initialize parent (union-find) array */
    for (int i = 0; i < n; i++)
        par[i] = -1;

    printf("The edges of minimum cost spanning tree are:\n");

    while (ne < n - 1) {
        min = 999;
        /* find the smallest edge */
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cost[i][j] < min && cost[i][j] != 0) {
                    min = cost[i][j];
                    a = i;
                    b =j;
                }
            }
        }

       u = a;
       v = b;
        while (par[u] != -1)
            u = par[u];
        while (par[v] != -1)
            v = par[v];

        if (u != v) {
            printf("from vertex %d to vertex %d and the cost = %d\n", a, b, min);
            mincost += min;
            par[v] = u;
            ne++;
        }

        /* mark this edge so it won't be chosen again */
        cost[a][b] = cost[b][a] = 999;
    }

    printf("The minimum cost is %d\n", mincost);
}

int main() {
    int i, j;
    printf("Enter the number of vertices: ");
    /*if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Invalid input for number of vertices\n");
        return 1;
    } */
    scanf("%d", &n);

    printf("enter the number of vertex:\n",n);

    for (i = 0; i < n; i++) 
        for (j = 0; j < n; j++) 
            scanf("%d", &cost[i][j]);
            
        
     

kruskal();
return 0;
}