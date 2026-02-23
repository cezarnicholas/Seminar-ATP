#include <stdio.h>

int main() {
    char nume[128];
    printf("Introdu numele fisierului: ");
    scanf("%127s", nume);

    FILE *fisier = fopen(nume, "w");
    fprintf(fisier, "ana\n");
    fclose(fisier);
}