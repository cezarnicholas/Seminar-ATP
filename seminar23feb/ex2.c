/*
    Sa se scrie un subprogram pentru crearea unui fisier text care sa contina elemente reale.
    In fisier sunt memorate elementele unui vector, cate un element pe fiecare linie.
    Cu un exemplu de utilizare.
*/
#include <stdio.h>
#include <assert.h>

void creeaza_fisier(const char *nume) {
    FILE *in = fopen(nume, "w");
    assert(in != NULL);

    float x;
    scanf("%f", &x);

    while (!feof(stdin)) {
        fprintf(in, "%3.2f\n", x);
        scanf("%f", &x);
    }

    fclose(in);
}   

int main() {
    creeaza_fisier("input.txt");
}