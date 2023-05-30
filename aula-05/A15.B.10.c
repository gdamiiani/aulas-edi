#include <stdio.h>

int fatorial(int n) {
    int out = 0;

    if (n == 0) {
        return 0;
    }

    out = n + fatorial(n - 1);

    return out;
}

int main() {
    int n;
    
    scanf("%d", &n);

    printf("%d\n", fatorial(n));
}
