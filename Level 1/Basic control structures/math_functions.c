#include <stdio.h>
#include <math.h>

double agnesi(double x) {
    return pow(1.0, 3) / (pow (1.0, 2) + pow(x, 2));
}

double bernoulli(double x) {
    return sqrt(sqrt(pow(1.0, 4) + 4 * pow(x, 2) * pow(1, 2)) - pow(x, 2) - pow(1.0, 2));
}

double q_hyperbola(double x) {
    return 1.0 / pow(x, 2);
}

void print(double y) {
    if (isnan(y)) {
        printf(" - ");
    } else {
        printf(" %.7lf ", y);
    }
}

int main() {
    for (double i = - M_PI; i <= M_PI; i += (M_PI * 2) / 41) {
        printf("%.7lf |", i);
        print(agnesi(i));
        printf("|");
        print(bernoulli(i));
        printf("|");
        print(q_hyperbola(i));
        printf("\n");
    }
    return 0;
}
