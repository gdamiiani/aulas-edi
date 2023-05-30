#include <stdio.h>

double func(double n) {
    double out = 0;

    for (int i = 1; i <= n; ++i) {
        out += 2 * i;
    }

    return out;
}

int main() {
    double n;

    printf("digite um numero: ");
    scanf("%lf", &n);

    double result = func(n);

    printf("resultado: %.2lf\n", result);

    return 0;
}
