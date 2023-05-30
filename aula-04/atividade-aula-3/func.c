#include "func.h"

int func(int n) {
    int out = 0;

    for (int i = 1; i <= n; ++i) {
        out += 2 * i;
    }

    return out;
}
