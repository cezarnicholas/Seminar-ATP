#include <stdio.h>

void addone(int *p) {
    *p = (*p) + 1;
}

int main() {
    int a = 5, *p = &a;
    addone(p);

    printf("%d\n", *p);
}