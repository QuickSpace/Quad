#include "utilities.h"
#include <TXLib.h>

bool equals(double a, double b) {
    const double EPSILON = 0.0001;
    return (fabs(a - b) < EPSILON);
}

bool isZero(double a) {
    return equals(a, 0);
}

void clearBuffer() {
    int currentChar = getchar();
    while (currentChar != '\n' && currentChar != EOF)
        currentChar = getchar();
}
