#include "utilities.h"
#include <TXLib.h>

bool equals(double a, double b) {
    const double EPSILON = 0.0001;
    return (fabs(a - b) < EPSILON);
}        // добавить isZero() +

bool isZero(double a) {
    return equals(a, 0);
}

void clearBuffer() {
    while (getchar() != '\n') {}
}
