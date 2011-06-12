#include <stdio.h>
#include <stdlib.h>

void exch(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int less(int a, int b){
   return a < b; 
}

int partition(int a[], int l, int r ){
    int i = l - 1, j = r;
    int v = a[r];
    for (;;) {
        while (less(a[i], v))
            i++;
        while (less(v, a[--j]))
            if (j == l) break;
        if(i >= j) break;
        exch(&a[i], &a[j]);
    }
    exch(&a[i], &a[r]);
    return i;
}

void quicksort(int a[], int l, int r){
    int i;
    if (r <= l) return;
    i = partition(a, l, r);
    quicksort(a, l, i - 1);
    quicksort(a, i + 1, r);
}

int main(int argc, const char *argv[])
{
    int i, N = atoi(argv[1]), len;
    printf("N %d\n", N);
    int a[N], b;
    if (argc != 2)
        printf("Usage: %s number of elements of an array\n", argv[0]);
    printf("plz input numbers:\n");
    for (i = 0; i < N; i++) {
        scanf("%d", &b);
        a[i] = b;
    }
    len = N - 1;
    quicksort(a, 1, len);
    printf("the array of a:\n");
    for (i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
