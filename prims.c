#include<stdio.h>

void prims(int arr[10][10], int n);

int main() {
    int cost[10][10] = {0};
    int i, j, n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        for(j = i + 1; j <= n; j++) {
            printf("Enter the weight between vertex %d and vertex %d: ", i, j);
            scanf("%d", &cost[i][j]);
            cost[j][i] = cost[i][j];
        }
    }

    printf("\nThe Adjacency Matrix Is: \n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }

    prims(cost, n);

    return 0;
}

void prims(int arr[10][10], int n) {
    int visited[10] = {0};
    int mincost = 0;
    int ne = 0;
    int i, j, a, b;
    visited[1] = 1;

    while (ne < n - 1) {
        int min = 999;

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (visited[i] == 1 && visited[j] == 0) {
                    if (arr[i][j] != 0 && arr[i][j] < min) {
                        a = i;
                        b = j;
                        min = arr[i][j];
                    }
                }
            }
        }

        visited[b] = 1;
        ne++;
        mincost += min;

        printf("\nEdge selected: (%d, %d) with weight = %d", a, b, min);

        arr[a][b] = 999;
        arr[b][a] = 999;
    }

    printf("\nThe minimum cost of the spanning tree is: %d\n", mincost);
}
