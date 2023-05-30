#include <stdio.h>

int func(int a) {
    int out = 1;

    for (int i = 1; i <= a; ++i) {
        out *= i;
    }

    return out;
}

int main() {
    int n;
    
    scanf("%d", &n);

    printf("%d\n", func(n));
}
