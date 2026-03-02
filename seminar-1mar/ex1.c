#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
    int nr_matricol;
    char nume[128];
    int an;
    int grupa;
    int numar_de_note;
    int note[15];
} student_t;

#define SIZE sizeof(student_t)

size_t citeste_student(student_t *cur) {
    size_t num_read = scanf("%d %127s %d %d %d", &(cur->nr_matricol), cur->nume, &(cur->an), &(cur->grupa), &(cur->numar_de_note));
    if (num_read < 5)
        return 0;

    for (int nota = 0; nota < cur->numar_de_note; nota++)
        num_read += scanf("%d", &(cur->note[nota]));

    if (num_read != 5 + cur->numar_de_note)
        return 0;

    return num_read;    
}

void output_student(student_t *cur) {
    printf("Numar matricol: %d\nNume: %-128s\nAn: %d\nGrupa: %d\nNumar de note: %d\n", cur->nr_matricol, cur->nume, cur->an, cur->grupa, cur->numar_de_note);

    for (int i = 0; i < cur->numar_de_note; ++i)
        printf("Nota %d: %d\n", i + 1, cur->note[i]);
    
    printf("\n");
}

int main() {
    FILE *bin = fopen("test.bin", "wb");
    assert(bin != NULL);

    student_t cur;
    while(citeste_student(&cur) > 5) {
        output_student(&cur);
        size_t num_written = fwrite(&cur, SIZE, 1, bin);
        assert(num_written == 1);
    }

    fclose(bin);

}