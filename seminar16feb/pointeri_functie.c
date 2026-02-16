#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    int (*operatie)(int, int);
    operatie = &add;

    printf("%d\n", operatie(2, 3));

    return 0;
}