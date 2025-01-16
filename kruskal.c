#include <stdio.h>
#include <stdlib.h>
#define INF 999

void display(int a[][30], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

int root(int v, int parent[30]) {
    while (parent[v] != 0) {
        v = parent[v];
    }
    return v;
}

void kruskal(int a[][30], int n) {
    int parent[30] = {0};
    int cost[30][30], mst[30][30] = {0};
    int ne = 0, x, y;
    float mincost = 0, min;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 0) {
                cost[i][j] = INF;
            } else {
                cost[i][j] = a[i][j];
            }
        }
    }

    printf("\nTHE COST MATRIX IS:\n");
    display(cost, n);
    while (ne < n - 1) {
        min = INF;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (min > cost[i][j]) {
                    min = cost[i][j];
                    x = i;
                    y = j;
                }
            }
        }

        if (root(x, parent) != root(y, parent)) {
            parent[y] = x; // Update parent
            mst[x][y] = mst[y][x] = min; // Add edge to MST
            mincost += min;
            ne++;
        }

        cost[x][y] = cost[y][x] = INF;
    }

    printf("\nTHE SPANNING TREE IS:\n");
    display(mst, n);
    printf("\nTHE MINIMUM COST OF THE SPANNING TREE IS: %g\n", mincost);
}

int main() {
    int a[30][30] = {0}, n;

    printf("\nENTER THE TOTAL NO. OF VERTICES: ");
    scanf("%d", &n);
    for (int r = 1; r <= n; r++) {
        for (int c = r + 1; c <= n; c++) {
            printf("\nCOST BETWEEN %d and %d: ", r, c);
            scanf("%d", &a[r][c]);
            a[c][r] = a[r][c];
        }
    }

    printf("\nTHE COST ADJACENCY MATRIX IS:\n");
    display(a, n);

    kruskal(a, n);

    return 0;
}
