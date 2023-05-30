#include <stdio.h>
#include <string.h>

typedef struct {
    int width;
    double height;
} Rectangle;

int main() {
    Rectangle r;

    printf("%zu\n", sizeof(r));
}
