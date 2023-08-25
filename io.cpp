#include <TXLib.h>
#include "utilities.h"
#include "io.h"

// input

bool readCoeffs(double* a, double* b, double* c) { // ������� �� ��������� asserts +
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

    return false;
} // ��������� � io +

// output
      // ��������� �������� input
void printRoots(RootsNum eqType, double* x1, double* x2) {
    assert(x1 != nullptr);
    assert(x2 != nullptr);

    switch (eqType) {
        case OneSol:
            printf("x: %.2lf\n", *x1);
            break;
        case InfiniteSol:
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

// �������� ������� �������� � declineExit() +
bool declineExit() { // ������������� ������� +
    const char CONFIRM_KEY = 'q'; // q +
    char input = 0;

    printf("Enter %c to quit (anything else to continue): ", CONFIRM_KEY);
    scanf(" %c", &input);
    clearBuffer();

    return input != CONFIRM_KEY;
}   // ��������� � io +
