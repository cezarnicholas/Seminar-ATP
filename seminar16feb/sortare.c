// Fie un subprogram care realizeaza sortarea elementelor unui vector dupa un anumit criteriu de sortare.
// Criteriul este dat de un pointer la o functie de comparare, care descrie relatia de ordine dintre doua elemente.
// Sa se scrie programul care realizeaza sortarea elementelor vectorului dupa criteriul dat (crescator / descrescator).

#include <stdio.h>
#include <stdlib.h>

int afisare(int *a, int n) {
    for (int i = 0; i < n; i++)
        printf("%d%c", a[i], (i == n - 1 ? '\n' : ' '));
}

int cmp_cresc(const void *x, const void *y) {
    int a = *(int*)x, b = *(int*)y;
    return (a - b);
}

int cmp_descresc(const void *x, const void *y) {
    int a = *(int*)x, b = *(int*)y;
    return (b - a);

}

int asc(int x, int y) {
    return x < y ? 0 : 1;
}

int desc(int x, int y) {
    return x > y ? 0 : 1;
}

void var1(int *a, int n, int(*comparator)(const void*, const void*)) {
    qsort(a, n, sizeof(int), comparator);
    afisare(a, n);
}

void var2(int *a, int n, int(*comparator)(int, int)) {
    for (int i = 0; i < n - 1; i++) {
        int poz = i;

        for (int j = i + 1; j < n; j++)
            if (comparator(a[poz], a[j]))
                poz = j;
        
        if (i != poz) {
            a[i] = a[i] ^ a[poz];
            a[poz] = a[i] ^ a[poz];
            a[i] = a[i] ^ a[poz];
        }
    }

    afisare(a, n);
}

int main() {
    int n;
    scanf("%d", &n);

    int *a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("------------------------------------------------\n");

    var1(a, n, cmp_cresc);
    var1(a, n, cmp_descresc);

    printf("------------------------------------------------\n");

    var2(a, n, asc);
    var2(a, n, desc);
    
    printf("------------------------------------------------\n");

    free(a);
}