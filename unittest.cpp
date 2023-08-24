#include <TXLib.h>
#include "unittest.h"
#include "solution.h"
#include "utilities.h"

int runTest(struct unitTestRef* valuesTest) { // указатель
    assert(unitTestRef != nullptr);
    double x1 = 0;
    double x2 = 0;

    double a = *valuesTest.a;
    double b = *valuesTest.b;
    double c = *valuesTest.c;
    double x1ref = *valuesTest.x1ref;
    double x2ref = *valuesTest.x2ref;
    EqType nRootsRef = *valuesTest.nRootsRef;

    EqType nRoots = solveEq(a, b, c, &x1, &x2);

    if (compareValues(x1, x2, x1ref, x2ref, nRoots, nRootsRef)) {  // условие в одну функцию +
        printf("FAILED: x1: %lf, x2: %lf, # of roots: %d; \n"
               "Expected: x1ref = %lf, x2ref = %lf, # of roots: %d\n",
                x1, x2, (int) nRoots, x1ref, x2ref, (int) nRootsRef);
        return 0;
    }

    printf("Successful\n");
    return 1;
}

int runAllTests() {
    const struct unitTestRef tests[] = {{4, 4, 1, -0.5, -0.5, TwoSol},
                                            {9, 1, 8,    0, 0, NoSol},
                                            {1, 5, 4,   -1, -4, TwoSol},
                                            {0, 0, 0,    0, 0, Infinite},
                                            {0, 2, 4,   -2, -2, OneSol},
                                            {1, 5, 4,  -40, -10, TwoSol}}; // здесь должен быть фейл

    int n = 0;

    const int ELEMENTS_NUM = sizeof(tests)/sizeof(tests[0]);

    for (int i = 0; i < ELEMENTS_NUM; i++) {
        n += runTest(&tests[i]); // набор тестов в массиве структур +
    }

    return n;
}

bool compareValues(double x1, double x2, double x1ref, double x2ref,
                EqType nRoots, EqType nRootsRef) {
    return !equals(x1, x1ref) || !equals(x2, x2ref) || nRoots != nRootsRef;
}
