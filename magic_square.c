#include <stdio.h>
#include <stdlib.h>

void display(int a[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("\t%d", a[i][j]);
        }
        printf("\n");
    }
}

void magic_cube(int a[][100], int n) {
    int i = 0, j, k, l, key;
    j = (n - 1) / 2;
    a[i][j] = 1;

    for (key = 2; key <= n * n; key++) {
        if (i >= 1)
            k = i - 1;
        else
            k = n - 1;

        if (j >= 1)
            l = j - 1;
        else
            l = n - 1;

        if (a[k][l] >= 1)
            i = (i + 1) % n;
        else {
            i = k;
            j = l;
        }
        a[i][j] = key;

        printf("\nAFTER %dth ITERATION:\n", key - 1);
        printf("\n----------------------------------------------------\n");
        display(a, n);
        printf("\n----------------------------------------------------\n");
    }
}

int main() {
    int magic[100][100], r, c, n;

    printf("\nENTER THE SIZE OF THE MATRIX: ");
    scanf("%d", &n);

    for (r = 0; r < n; r++) {
        for (c = 0; c < n; c++) {
            magic[r][c] = 0;
        }
    }

    printf("\nNOW THE MATRIX IS:--\n");
    display(magic, n);

    if (n % 2 == 0) {
        printf("\nTHE SIZE OF THE MATRIX IS EVEN: OPERATION TERMINATED\n");
        exit(0);
    } else {
        magic_cube(magic, n);
    }

    printf("\nTHE MAGIC CUBE IS:\n");
    printf("\n----------------------------------------------------\n");
    display(magic, n);
    printf("\n----------------------------------------------------\n");

    return 0;
}
