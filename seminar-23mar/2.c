#include <stdio.h>
#include <stdlib.h>

int count_negatives(int *v, int lo, int hi) {
    int rez;
    
    if (lo == hi) {
        rez = (v[lo] < 0);
    } else {
        int mid = (lo + hi) / 2;

        int jum_st = count_negatives(v, lo, mid);
        int jum_dr = count_negatives(v, mid + 1, hi);

        rez = jum_st + jum_dr;
    }

    return rez;
}

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);

    int *v = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    int ans = count_negatives(v, 0, n);
    printf("%d\n", ans);

    free(v);
}