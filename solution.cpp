#include <TXLib.h>
#include "solution.h"
#include "utilities.h"

RootsNum solveSquare(double a, double b, double c, double* x1, double* x2) {
    assert(x1 != nullptr);
    assert(x2 != nullptr);

    if(isZero(a))
        return solveLinear(b, c, x1, x2);

    double d = b * b - 4 * a * c;

    if(d < 0)
        return NO_SOL;

    if(isZero(d)) {
        *x1 = *x2 = -b/(2*a);
        return TWO_SOL;
    }

    double sqrt_d = sqrt(d);

    *x1 = (-b + sqrt_d) / (2*a);
    *x2 = (-b - sqrt_d) / (2*a);

    return TWO_SOL;
}

RootsNum solveLinear(double b, double c, double* x1, double* x2) {
    assert(x1 != nullptr);
    assert(x2 != nullptr);

    if(isZero(b))
        return isZero(c) ? INFINITE_SOL : NO_SOL;

    double linearRoot = -c/b;
    *x1 = *x2 = isZero(linearRoot) ? 0 : linearRoot;

    return ONE_SOL;
}
