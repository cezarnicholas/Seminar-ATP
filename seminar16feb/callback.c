#include <stdio.h>

typedef int (*Operatie)(int, int);

int aduna(int a, int b) {
    return a + b;
}

int scade(int a, int b) {
    return a - b;
}

int inmulteste(int a, int b) {
    return a * b;
}

int imparte(int a, int b) {
    return a / b;
}

// functie generica care accepta un callback
int aplica_operatie(int x, int y, Operatie op) {
    return op(x, y);
}

int main() {
    int a = 40, b = 20;
    // 40 + 20 = 60
    printf("%d + %d = %d\n", a, b, aplica_operatie(a, b, aduna));
    printf("%d - %d = %d\n", a, b, aplica_operatie(a, b, scade));
    printf("%d * %d = %d\n", a, b, aplica_operatie(a, b, inmulteste));
    printf("%d / %d = %d\n", a, b, aplica_operatie(a, b, imparte));

    
}