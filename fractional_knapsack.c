#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void display(float a1[], float a2[], float a3[], int n) {
    int i;
    for (i = 1; i <= n; i++) {
        printf("%d\t%0.2f\t%0.2f\t%0.2f\n", i, a1[i], a2[i], a3[i]);
    }
}

void swap(float *x, float *y) {
    float t;
    t = *x;
    *x = *y;
    *y = t;
}

float min(float a, float b) {
    return (a < b) ? a : b;
}

void knapsack(int item[], float w[], float b[], float wt, int n) {
    int i, j, x, temp;
    float amount, benefit = 0;
    float r[30], solution[30];
    
    for (i = 1; i <= n; i++) {
        r[i] = b[i] / w[i];
    }
    
    printf("\nDISPLAY THE UNIT VALUE OF THE CORRESPONDING ITEMS:-");
    printf("\nITEM\tWEIGHT\tBENEFIT\tRATIO\n");
    display(w, b, r, n);
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i; j++) {
            if (r[j] < r[j + 1]) {
                temp = item[j];
                item[j] = item[j + 1];
                item[j + 1] = temp;
                swap(&w[j], &w[j + 1]);
                swap(&b[j], &b[j + 1]);
                swap(&r[j], &r[j + 1]);
            }
        }
    }
    
    printf("\nAFTER SORTING-\n");
    printf("\nITEM\tWEIGHT\tBENEFIT\tRATIO\n");
    for (i = 1; i <= n; i++) {
        printf("%d\t%0.2f\t%0.2f\t%0.2f\n", item[i], w[i], b[i], r[i]);
    }
    
    x = 1;
    do {
        amount = min(wt, w[x]);
        solution[x] = amount;
        benefit = benefit + solution[x] * r[x];
        wt = wt - amount;
        x = x + 1;
    } while (wt > 0);
    
    printf("\nTHE ITEM TAKEN INTO KNAPSACK AND THEIR WEIGHT");
    printf("\nitem\tanswer-\n");
    for (i = 1; i <= n; i++) {
        printf("%d\t%2.3f\n", item[i], solution[i]);
    }
    printf("\nTHE BENEFIT IS=%g", benefit);
}

void main() {
    int n, i;
    int item[30];
    float benefit[30], weight[30], wt;
    
    printf("\nENTER THE NUMBER OF THE ITEM:-");
    scanf("%d", &n);
    printf("\nENTER THE WEIGHT AND BENEFIT OF THE ITEMS:-\n");
    for (i = 1; i <= n; i++) {
        printf("\nENTER THE WEIGHT AND BENEFIT OF ITEM NO'S %d:", i);
        scanf("%f %f", &weight[i], &benefit[i]);
        item[i] = i;
    }
    
    printf("\nTHE WEIGHT AND THE BENEFIT OF THE ITEM IS:-\n");
    printf("\nITEM\tWEIGHT\tBENEFIT\n");
    for (i = 1; i <= n; i++) {
        printf("%d\t%0.2f\t%0.2f\n", item[i], weight[i], benefit[i]);
    }
    
    printf("\nENTER THE WEIGHT OF KNAPSACK:-");
    scanf("\n%f", &wt);
    
    knapsack(item, weight, benefit, wt, n);
}
