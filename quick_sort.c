#include <stdio.h>

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

int partition(int a[], int lb, int ub) {
    int pivot = a[lb];
    int start = lb + 1, end = ub;

    do {
        while (a[start] <= pivot && start <= ub) {
            start++;
        }
        while (a[end] > pivot) {
            end--;
        }
        if (start < end) {
            swap(&a[start], &a[end]);
        }
    } while (start < end);

    swap(&a[lb], &a[end]);
    return end;
}

void display(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("\t%d", a[i]);
    }
    printf("\n");
}

void quicksort(int a[], int lbound, int ubound) {
    if (lbound < ubound) {
        int loc = partition(a, lbound, ubound);
        quicksort(a, lbound, loc - 1);
        quicksort(a, loc + 1, ubound);
    }
}

int main() {
    int a[50], size;

    printf("\nDeclare the size of the array: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        printf("\nEnter the element at index %d: ", i);
        scanf("%d", &a[i]);
    }

    printf("\nBEFORE QUICKSORT:\n");
    display(a, size);

    quicksort(a, 0, size - 1);

    printf("\nAFTER QUICKSORT:\n");
    display(a, size);

    return 0;
}
