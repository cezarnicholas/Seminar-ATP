#include <stdio.h>

int n, sol[15];
int valid(int p) {
    for (int i = 1; i < p; i++)
        if (sol[i] == sol[p])
            return 0;

    return 1;
}

void afiseaza() {
    printf("{");
    
    for (int i = 1; i <= n; i++)
        printf("%d%s", sol[i], (i == n ? "" : ", "));

    printf("}\n");
}

void permutare(int p) {
    for (int i = 1; i <= n; i++) {
        sol[p] = i;
        if (valid(p)) {
            if (p == n)
                afiseaza();
            else
                permutare(p + 1);
        }
    }
}

int main() {
    scanf("%d", &n);
    permutare(1);
}