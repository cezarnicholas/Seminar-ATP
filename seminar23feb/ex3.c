/*
    Sa se scrie programul care creeaza un fisier text si memoreaza informatii despre produsele
    aflate in depozitul unui magazin. Informatiile care se retin despre produse sunt:
    1) codul produsului - int
    2) numele produsului - char[20]
    3) cantitatea - int
    4) pret - float
*/

#include <stdio.h>
#include <assert.h>

typedef struct {
    int cod;
    char nume[20];
    int cantitate;
    float pret;
} produs_t;

void output_produs(FILE *f, produs_t p) {
    fprintf(f, "Cod: %03d\nNume: %20s\nCantitate: %d kg\nPret: %.2f lei\n\n", p.cod, p.nume, p.cantitate, p.pret);
}

void creeaza_fisier(const char *nume) {
    FILE *fisier_produse = fopen(nume, "w");
    assert(fisier_produse != NULL);

    produs_t produs;
    while (scanf("%d %19s %d %f", &produs.cod, produs.nume, &produs.cantitate, &produs.pret) == 4) {
        output_produs(fisier_produse, produs);
    }

    fclose(fisier_produse);
}

int main() {
    creeaza_fisier("produse.txt");
}