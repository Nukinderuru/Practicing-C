#include <stdio.h>

int is_divisor(int a, int b) {
    int res = 0;
    while (a >= b) {
        res++;
        a -= b;
        if (a == 0) {
            res = 1;
            break;
        } else {
            res = 0;
        }
    }
    return res;
}

int main() {
    int a, count = 0;
    if (scanf("%d", &a) != 1) {
        printf("n/a");
        return 1;
    }
    char c;
    if ((c = getchar()) != '\n') {
        printf("n/a");
        return 1;
    }
    if (a < 0) {
        a = - a;
    }
    for (int i = a - 1; i > 1; --i) {
        if (is_divisor(a, i)) {
            count = 0;
            for (int j = i - 1; j > 1; --j) {
                if (is_divisor(i, j)) {
                    count++;
                }
            }
            if (count == 0 && i != 0) {
                printf("%d", i);
                break;
            }
        }
    }
    return 0;
}
