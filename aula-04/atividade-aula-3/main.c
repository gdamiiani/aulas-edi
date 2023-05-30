#include <stdio.h>

#include "func.h"

int main() {
    int n;

    printf("digite um numero: ");
    scanf("%d", &n);

    int result = func(n);

    printf("resultado: %d\n", result);

    return 0;
}
