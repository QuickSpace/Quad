#include <TXLib.h>
#include "utilities.h"
#include "io.h"

// input

bool readCoeffs(double* a, double* b, double* c) { // ������� �� ��������� asserts
    assert(a != nullptr);
    assert(b != nullptr);
    assert(c != nullptr);
    printf("Enter coefficients: ");

    if (scanf("%lf%lf%lf", a, b, c) < 3)
    {
        printf("Incorrect input, try again!\n");
        clearBuffer();
        return true;
    }

    return false;
} // ��������� � io +

// output
      // ��������� �������� input
void printRoots(EqType eqType, double* x1, double* x2) {
    assert(x1 != nullptr);
    assert(x2 != nullptr);
    switch (eqType) {
        case OneSol:
            printf("x: %.2lf\n", *x1);
            break;
        case Infinite:
            printf("Infinitely many solutions\n");
            break;
        case NoSol:
            printf("No solutions\n");
            break;
        // ���������� enum +
        case TwoSol:
            printf("x1: %.2lf \nx2: %.2lf\n", *x1, *x2);
            break;
        default:
            assert(0 && "Unknown number of roots\n");
            break; // assert +
    }
} // ��������� � io +

// ������������� ������ �� �����

bool confirmTests() {
    const int CONFIRM_KEY = 5;
    int input = 0;

    printf("Enter %d to run tests (anything else to just continue): ", CONFIRM_KEY);
    scanf("%d", &input);
    clearBuffer();

    return input == CONFIRM_KEY;
}  // ��������� � io +

bool confirmExit() {
    const int CONFIRM_KEY = 4;
    int input = 0;

    printf("Enter %d to continue (anything else to quit): ", CONFIRM_KEY);
    scanf("%d", &input);
    clearBuffer();

    return input == CONFIRM_KEY;
}
