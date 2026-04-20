#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

float knapsack(float gm, float *v, float *g, int n) {
    if (gm == 0 || n == 0)
        return 0;

    int il_alegem = 0;
    if (g[n - 1] <= gm)
        il_alegem = v[n - 1] + knapsack(gm - g[n - 1], v, g, n - 1);


    int nu_il_alegem = knapsack(gm, v, g, n - 1);
    if (il_alegem > nu_il_alegem)
        return il_alegem;
    else
        return nu_il_alegem;
}

typedef struct {
    float castig_unitar;
    float valoare;
    float greutate;
} obiect_t;

int cmp(const void *a, const void *b) {
    float fa = (*(obiect_t*)a).castig_unitar;   
    float fb = (*(obiect_t*)b).castig_unitar;   
    if (fb > fa) return 1;
    if (fa < fb) return -1;
    return 0;
}

float rucsac_nerecursiv(float gm, float *v, float *g, int n) {  
    obiect_t *obiecte = (obiect_t*)malloc(n * sizeof(obiect_t));

    for (int i = 0; i < n; i++)
        obiecte[i] = (obiect_t){(v[i] / g[i]), v[i], g[i]};

    qsort(obiecte, n, sizeof(obiect_t), cmp);

    float total = 0;
    int cur = 0;

    while (gm >= obiecte[cur].greutate && cur < n) {
        gm -= obiecte[cur].greutate;
        total += obiecte[cur].valoare;
        cur++;
    }
    
    free(obiecte);
    return total;
}

int main() {
    int n;
    scanf("%d", &n);

    float capacitate_maxima;
    scanf("%f", &capacitate_maxima);

    float *valori     = (float*)malloc(n * sizeof(float));
    float *greutate   = (float*)malloc(n * sizeof(float));

    assert(valori != NULL);
    assert(greutate != NULL);

    for (int i = 0; i < n; i++) {
        printf("Valoarea si greutatea obiectului %d: ", i);
        scanf("%f %f", &valori[i], &greutate[i]);
    }

    float max_obt1 = knapsack(capacitate_maxima, valori, greutate, n);
    float max_obt2 = rucsac_nerecursiv(capacitate_maxima, valori, greutate, n);
    printf("%.2f %.2f", max_obt1, max_obt2);

    free(valori);
    free(greutate);

}