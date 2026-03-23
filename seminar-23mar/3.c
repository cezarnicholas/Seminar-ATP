// Sa se scrie subprogramul recursiv care determina produsul scalar dintre doi vectori.
// Sa se scrie si programul apelator.
// Test saptamana viitoare din fisiere binare organizate secvential si relativ.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int dotproduct1(int *a, int *b, int n) {
    int rez;
    if (n == 0) {
        rez = 0;
    } else {
        rez = dotproduct1(a, b, n - 1);
        rez += a[n - 1] * b[n - 1];
    }

    return rez;
}

int dotproduct2(int *a, int *b, int lo, int hi) {
    int rez;

    if (lo == hi) {
        rez = a[lo] * b[lo];
    } else {
        int mid = (lo + hi) / 2;

        int jum_st = dotproduct2(a, b, lo, mid);
        int jum_dr = dotproduct2(a, b, mid + 1, hi);

        rez = jum_st + jum_dr;
    }

    return rez;
}

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);

    int *a, *b;
    a = (int*)malloc(n * sizeof(int));
    b = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);

    int p1 = dotproduct1(a, b, n);
    int p2 = dotproduct2(a, b, 0, n);

    assert(p1 == p2);
    printf("%d %d\n", p1, p2);
    
    free(a);
    free(b);
}
