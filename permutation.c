#include <stdio.h>
#include <string.h>

static int count = 0;

void per(char a[], int k, int n) {
    char t;
    if (k == n) {
        for (int i = 0; i <= n; i++) {
            printf("%c", a[i]);
        }
        printf("\n");
        count++;
    } else {
        for (int i = k; i <= n; i++) {
            t = a[k];
            a[k] = a[i];
            a[i] = t;

            per(a, k + 1, n);

            t = a[k];
            a[k] = a[i];
            a[i] = t;
        }
    }
}

int main() {
    char set[100];
    int n;

    printf("Enter the elements of the set: ");
    fgets(set, sizeof(set), stdin);

    set[strcspn(set, "\n")] = '\0';

    n = strlen(set);

    printf("The set is:\n");
    for (int i = 0; i < n; i++) {
        printf("%c ", set[i]);
    }
    printf("\n");

    printf("Permutations:\n");
    per(set, 0, n - 1);

    printf("Total permutations: %d\n", count);
    return 0;
}
