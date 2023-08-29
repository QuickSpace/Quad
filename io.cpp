#include <TXLib.h>
#include <math.h>
#include "utilities.h"
#include "io.h"

bool readCoeffs(double* a, double* b, double* c) {
    assert(a != nullptr);
    assert(b != nullptr);
    assert(c != nullptr);

    printf("Enter coefficients: ");

    if (scanf("%lf %lf %lf", a, b, c) < 3)
    {
        printf("Incorrect input, try again!\n");
        clearBuffer();
        return true;
    }

    clearBuffer();
    return false;
}

void printRoots(RootsNum rootsNum, double* x1, double* x2) {
    assert(x1 != nullptr);
    assert(x2 != nullptr);
    assert(isfinite(*x1) != 0);
    assert(isfinite(*x2) != 0);

    switch (rootsNum) {
        case ONE_SOL:
            printf("x: %.2lf\n", *x1);
            break;
        case INFINITE_SOL:
            printf("Infinitely many solutions\n");
            break;
        case NO_SOL:
            printf("No solutions\n");
            break;
        case TWO_SOL:
            printf("x1: %.2lf \nx2: %.2lf\n", *x1, *x2);
            break;
        default:
            assert(0 && "Unknown number of roots\n");
            break;
    }
}

bool confirmExit() {
    const char CONFIRM_KEY = 'q';
    char input = 0;

    printf("Enter %c to quit (anything else to continue): ", CONFIRM_KEY);
    scanf(" %c", &input);
    clearBuffer();

    return input == CONFIRM_KEY;
}
