#include <TXLib.h>
#include "unittest.h"
#include "solution.h"
#include "utilities.h"

int runTest(const UnitTest* valuesTest) { // ��������� +
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

    if (checkValues(x1, x2, x1req, x2req, nRoots, nRootsReq)) {  // ������� � ���� ������� +
        printf("FAILED: x1: %lf, x2: %lf, # of roots: %d; \n"
               "Expected: x1req = %lf, x2req = %lf, # of roots: %d\n",
                x1, x2, (int) nRoots, x1req, x2req, (int) nRootsReq);
        return 0;
    }

    printf("Successful\n");
    return 1;
}

int runAllTests() {
    const UnitTest tests[] = {{4, 4, 1, -0.5, -0.5, TwoSol},
                             {9, 1, 8,    0, 0, NoSol},
                             {1, 5, 4,   -1, -4, TwoSol},
                             {0, 0, 0,    0, 0, InfiniteSol},
                             {0, 2, 4,   -2, -2, OneSol},
                             {1, 5, 4,  -40, -10, TwoSol}}; // ����� ������ ���� ����

    int successTestsNum = 0;

    const int TESTS_NUM = sizeof(tests)/sizeof(tests[0]);

    for (int i = 0; i < TESTS_NUM; i++) {
        successTestsNum += runTest(&tests[i]); // ����� ������ � ������� �������� +
    }

    return successTestsNum;
}

bool checkValues(double x1, double x2, double x1req, double x2req,
                RootsNum nRoots, RootsNum nRootsReq) {
    return !equals(x1, x1req) || !equals(x2, x2req) || nRoots != nRootsReq;
}
