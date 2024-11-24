#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void) {
    srand(time(NULL));

    double randomValue = (double)rand() / (RAND_MAX + 1.0);
    double sineValue = sin(randomValue);

    printf("Random value: %.6f\n", randomValue);
    printf("Sine of random value: %.6f\n", sineValue);

    return 0;
}
