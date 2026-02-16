#include <stdio.h>

void add_one(int *p) {
    *p = (*p) + 1;
}

int main() {
    int a = 5, *p = &a;
    add_one(p);

    printf("%d\n", *p);
}