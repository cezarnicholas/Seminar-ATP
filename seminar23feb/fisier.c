#include <stdio.h>

int main() {
    FILE *fisier = fopen("abc.txt", "w");
    fprintf("fisier", "ana");
    fclose(fisier);
}