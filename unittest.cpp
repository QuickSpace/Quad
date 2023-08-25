#include <TXLib.h>
#include "unittest.h"
#include "solution.h"
#include "utilities.h"

int runTest(const UnitTest* valuesTest) { // указатель +
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

    if (checkValues(x1, x2, x1req, x2req, nRoots, nRootsReq)) {  // условие в одну функцию +
        printf("FAILED: x1: %lf, x2: %lf, # of roots: %d; \n"
               "Expected: x1req = %lf, x2req = %lf, # of roots: %d\n",
                x1, x2, (int) nRoots, x1req, x2req, (int) nRootsReq);
        return 0;
    }

    printf("Successful\n");
    return 1;
}

int runAllTests(UnitTest tests[], int testsNum) {

    int successTestsNum = 0;

    for (int i = 0; i < testsNum; i++) {
        successTestsNum += runTest(&tests[i]); // набор тестов в массиве структур +
    }

    return successTestsNum;
}

bool checkValues(double x1, double x2, double x1req, double x2req,
                RootsNum nRoots, RootsNum nRootsReq) {
    return !equals(x1, x1req) || !equals(x2, x2req) || nRoots != nRootsReq;
}
