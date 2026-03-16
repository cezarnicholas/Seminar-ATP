#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int nr_matricol;
    char nume_prenume[30];
    int grupa;
    char punctaj_practica;
    char puncte_teme[10];
    char punctaj_examen;
} student_t;

#define SIZE sizeof(student_t)

void output_student(student_t s) {
    printf("===================================\n");
    printf("%d %s %d\n", s.nr_matricol, s.nume_prenume, s.grupa);
    printf("Punctaj practica: %d\n", s.punctaj_practica);
    for (int i = 0; i < 10; i++)
        printf("Puncte tema %d: %d\n", i + 1, s.puncte_teme[i]);
    printf("Punctaj examen: %d\n", s.punctaj_examen);
    printf("===================================\n");
}

void output_tabel(FILE *txt, int cnt, student_t s) {
    fprintf(txt, "%-7d   %-7d     %-36s%-5d     %-8d    ",
            cnt,
            s.nr_matricol,
            s.nume_prenume,
            s.grupa,
            s.punctaj_practica);

    for (int i = 0; i < 10; i++)
        fprintf(txt, "%d ", s.puncte_teme[i]);

    fprintf(txt, "      %-6d\n", s.punctaj_examen);
}

void listeaza_studenti(FILE *bin) {
    FILE *txt = fopen("Puncte.txt", "w");

    fprintf(txt, "Nr. crt   Nr. mat     Nume                                Grupa     Practica    Teme                      Examen   \n");

    size_t begin = 0;
    fseek(bin, 0, SEEK_END);
    size_t end = ftell(bin);
    rewind(bin);

    int nr_studenti = (end - begin) / SIZE;
    student_t *studenti = (student_t*)malloc(nr_studenti * SIZE);
    fread(studenti, SIZE, nr_studenti, bin);

    for (int i = 0; i < nr_studenti; i++)
        output_tabel(txt, i + 1, studenti[i]);

    free(studenti);
    fclose(txt);
}

int main() {
    FILE *bin = fopen("Puncte.dat", "rb+");

    int nr_matricol;
    printf("Introdu nr matricol: ");
    scanf("%d", &nr_matricol);

    int punctaj;
    printf("Introdu punctaj: ");
    scanf("%d", &punctaj);

    while (!feof(stdin)) {
        printf("%d %d\n", nr_matricol, punctaj);

        student_t stud;
        int gasit = 0;

        while (gasit == 0 && fread(&stud, SIZE, 1, bin))
            if (stud.nr_matricol == nr_matricol)
                gasit = 1;

        if (gasit == 1) {
            stud.punctaj_examen = punctaj;

            fseek(bin, -SIZE, SEEK_CUR);
            fwrite(&stud, SIZE, 1, bin);
            printf("Overwritten!\n\n");
        } else {
            printf("Nu exista un student cu acest numar matricol!\n");
        }

        rewind(bin);

        printf("Introdu nr matricol: ");
        scanf("%d", &nr_matricol);

        printf("Introdu punctaj: ");
        scanf("%d", &punctaj);
    }

    listeaza_studenti(bin);
    fclose(bin);

    return 0;
}