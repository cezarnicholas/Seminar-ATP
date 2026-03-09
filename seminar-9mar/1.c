// Fisiere binare organizate relative

/*
    Datele se vor prelua de la tastatura.

    Variabila de tip char care testeaza daca produsul este valid sau invalid.
    char is == 0 ? "invalid" : "valid"
*/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct {
    char denumire[20];
    float pret;
    int cantitate;
    char is;
} produs_t;

#define SIZE sizeof(produs_t)

const produs_t empty = { "\0", 0, 0, 0 };

int citeste_produs(produs_t *produs) {
    printf("\n====================================\n");         

    printf("Introdu denumirea: ");
    int n = scanf("%19s", produs->denumire);

    printf("Introdu pretul: ");
    n += scanf("%f", &(produs->pret));

    printf("Introdu cantitatea: ");
    n += scanf("%d", &(produs->cantitate));

    printf("\n====================================\n");

    return ( (produs->is = n == 3) && (n == 3) );
}

void output_produs(produs_t produs) {
    printf("Denumire: %s\nPret:%3.2f\nCantitate:%d", produs.denumire, produs.pret, produs.cantitate);
    printf("\n\n");
}

int calc_numar_inregistrari(FILE *bin) {
    size_t begin = 0;

    fseek(bin, 0, SEEK_END);
    size_t end = ftell(bin);
    fseek(bin, 0, SEEK_SET);

    int numar_inregistrari = (end - begin) / SIZE;
    return numar_inregistrari;
}

void scrie_fisier(const char *nume_fisier) {
    FILE *bin = fopen(nume_fisier, "wb");
    assert(bin != NULL);

    produs_t produs;
    while (citeste_produs(&produs)) {
       fwrite(&produs, SIZE, 1, bin);
    }

    fclose(bin);
}

int main(int argc, char *argv[]) {
    assert(SIZE == 32);

    char nume_fisier[128];
    printf("Introdu numele fisierului: ");
    scanf("%127s", nume_fisier);

    scrie_fisier(nume_fisier);
    FILE *bin = fopen(nume_fisier, "rb+");

    freopen(NULL, "rw", stdin);

    printf("Introdu codul produsului: ");
    int cod;
    while (scanf("%d", &cod) == 1) {
        int numar_inregistrari = calc_numar_inregistrari(bin);
        produs_t produs;

        if (cod >= numar_inregistrari) {
            int diff = cod - numar_inregistrari;
            fseek(bin, 0, SEEK_END);

            for (int i = 0; i < diff; i++)
                fwrite(&empty, SIZE, 1, bin);

            citeste_produs(&produs);
            fwrite(&produs, SIZE, 1, bin);

            output_produs(produs);
        } else {
            fseek(bin, cod * SIZE, SEEK_SET);
            if (fread(&produs, SIZE, 1, bin) != 1)
                produs = empty;

            if (produs.is == 0) {
                fseek(bin, cod * SIZE, SEEK_SET);
                citeste_produs(&produs);
                fwrite(&produs, SIZE, 1, bin);
            }

            output_produs(produs);
        }

        fflush(bin);
        printf("Introdu codul produsului: ");
    }


    fclose(bin);
    return 0;
}