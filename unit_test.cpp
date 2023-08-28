#include <TXLib.h>
#include "unit_test.h"
#include "solution.h"
#include "utilities.h"

void runTest(const UnitTest* valuesTest, int* testsNum) {
    assert(valuesTest != nullptr);

    double x1 = 0;
    double x2 = 0;

    double a = valuesTest -> a;
    double b = valuesTest -> b;
    double c = valuesTest -> c;
    double x1req = valuesTest -> x1req;
    double x2req = valuesTest -> x2req;
    RootsNum nRootsReq = valuesTest -> nRootsReq;

    RootsNum nRoots = solveSquare(a, b, c, &x1, &x2);

    if (!equals(x1, x1req) ||
        !equals(x2, x2req) || nRoots != nRootsReq)
    {
        printf("FAILED: x1: %lf, x2: %lf, # of roots: %d; \n"
               "Expected: x1req = %lf, x2req = %lf, # of roots: %d\n",
                x1, x2, nRoots, x1req, x2req, (int) nRootsReq);
    }
    else
    {
        printf("Successful\n");
        *testsNum += 1;
    }
}
