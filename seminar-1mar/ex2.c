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

void output_student(student_t *cur) {
    printf("Numar matricol: %d\nNume: %-128s\nAn: %d\nGrupa: %d\nNumar de note: %d\n", cur->nr_matricol, cur->nume, cur->an, cur->grupa, cur->numar_de_note);

    for (int i = 0; i < cur->numar_de_note; ++i)
        printf("Nota %d: %d\n", i + 1, cur->note[i]);
    
    printf("\n");
}

int main(int argc, char *argv[]) {
    FILE *bin = fopen("test.bin", "rb");
    assert(bin != NULL);

    size_t begin = ftell(bin);
    fseek(bin, 0, SEEK_END);
    size_t end = ftell(bin);
    fseek(bin, 0, SEEK_SET);

    size_t bytes = end - begin;
    size_t num_elements = bytes / SIZE;

    student_t *studenti = (student_t*)malloc(num_elements * SIZE);
    fread(studenti, SIZE, num_elements, bin);

    for (int i = 0; i < num_elements; ++i)
        output_student(&studenti[i]);

    free(studenti);
}