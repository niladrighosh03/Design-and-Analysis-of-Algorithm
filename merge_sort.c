#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void DISPLAY(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\t%d", a[i]);
    }
    printf("\n");
}

void merge(int a[], int low, int mid, int high) {
    int h = low, i = low, j = mid + 1, k;
    int b[30];

    while ((h <= mid) && (j <= high)) {
        if (a[h] <= a[j]) {
            b[i] = a[h];
            h++;
        } else {
            b[i] = a[j];
            j++;
        }
        i++;
    }

    if (h > mid) {
        for (k = j; k <= high; k++) {
            b[i] = a[k];
            i++;
        }
    } else {
        for (k = h; k <= mid; k++) {
            b[i] = a[k];
            i++;
        }
    }

    for (k = low; k <= high; k++) {
        a[k] = b[k];
    }
}

void mergesort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int a[30];
    int n;

    printf("\nENTER THE SIZE OF THE ARRAY: ");
    scanf("%d", &n);

    printf("\n***********************************\n");
    printf("\nENTER THE ELEMENTS IN THE ARRAY:\n");
    for (int i = 0; i < n; i++) {
        printf("ENTER THE ELEMENT AT POSITION-%d: ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("\nTHE ARRAY BEFORE SORTING:\n");
    DISPLAY(a, n);

    mergesort(a, 0, n - 1);

    printf("\nAFTER SORTING:\n");
    DISPLAY(a, n);

    return 0;
}
