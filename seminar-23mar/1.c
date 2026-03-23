// Sa se scrie subprogramul recursiv care determina numarul de elemente negative dintr-un vector.
// Se va scrie si programul apelator.
#include <stdio.h>
#include <stdlib.h>

int count_negatives(int *v, int n) {
    int rez;
    if (n == 0) {
        rez = 0;
    }
    else {
        rez = count_negatives(v, n - 1);
        if (v[n - 1] < 0)
            rez += 1;
    }

    return rez;
}

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);

    int *v = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    int ans = count_negatives(v, n);

    printf("%d\n", ans);
    free(v);
}