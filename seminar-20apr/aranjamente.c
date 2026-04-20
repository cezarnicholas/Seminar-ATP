#include <stdio.h>

int n, k, sol[15], total = 0;
int valid(int p) {
    for (int i = 1; i < p; i++)
        if (sol[i] == sol[p])
            return 0;

    return 1;
}

void afiseaza() {
    printf("(");

    for (int i = 1; i <= k; i++)
        printf("%d%s", sol[i], (i == k ? "" : ", "));

    printf(")\n");
}

void aranjamente(int p) {
    for (int i = 1; i <= n; i++) {
        sol[p] = i;
        if (valid(p)) {
            if (p == k) {
                afiseaza();
                total++;
            }
            else
                aranjamente(p + 1);
        }
    }
}

int main() {
    printf("Aranjamente de N luate cate K: ");
    scanf("%d %d", &n, &k);

    aranjamente(1);
    printf("Total aranjamente: %d\n", total);
}