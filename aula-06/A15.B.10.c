#include <stdio.h>

int func(int n) {
    int out = 0;

    if (n == 0) {
        return 0;
    }

    out = n + func(n - 1);

    return out;
}

int main() {
    int n;
    
    scanf("%d", &n);

    printf("%d\n", func(n));
}
