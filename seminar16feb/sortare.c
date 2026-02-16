// Fie un subprogram care realizeaza sortarea elementelor unui vector dupa un anumit criteriu de sortare.
// Criteriul este dat de un pointer la o functie de comparare, care descrie relatia de ordine dintre doua elemente.
// Sa se scrie programul care realizeaza sortarea elementelor vectorului dupa criteriul dat (crescator / descrescator).

#include <stdio.h>
#include <stdlib.h>

int cmp_cresc(const void *x, const void *y) {
    int a = *(int*)x, b = *(int*)y;
    return (a - b);
}

int cmp_descresc(const void *x, const void *y) {
    int a = *(int*)x, b = *(int*)y;
    return (b - a);
}

int main() {
    int n;
    scanf("%d", &n);

    int *a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    qsort(a, n, sizeof(int), cmp_cresc);
    for (int i = 0; i < n; i++)
        printf("%d%c", a[i], (i == n - 1 ? '\n' : ' '));

    qsort(a, n, sizeof(int), cmp_descresc);
    for (int i = 0; i < n; i++)
        printf("%d%c", a[i], (i == n - 1 ? '\n' : ' '));

    free(a);
}