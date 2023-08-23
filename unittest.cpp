#include <TXLib.h>
#include "unittest.h"
#include "solution.h"
#include "utilities.h"

int solutionTest(struct unitStruct testStruct) { // указатель
    double x1 = 0;
    double x2 = 0;

    double a = testStruct.a;
    double b = testStruct.b;
    double c = testStruct.c;
    double x1ref = testStruct.x1ref;
    double x2ref = testStruct.x2ref;
    SolNumber nRootsRef = testStruct.nRootsRef;

    SolNumber nRoots = solveEq(a, b, c, &x1, &x2);

    if (testInputs(x1, x2, x1ref, x2ref, nRoots, nRootsRef)) {  // условие в одну функцию +
        printf("FAILED: x1: %lf, x2: %lf, # of roots: %d; \n"
               "Expected: x1ref = %lf, x2ref = %lf, # of roots: %d\n",
                x1, x2, (int) nRoots, x1ref, x2ref, (int) nRootsRef);
        return 0;
    }

    printf("Successful\n");
    return 1;
}

int testAll() {
    const struct unitStruct testArray[] = {{4, 4, 1, -0.5, -0.5, TwoSol},
                                            {9, 1, 8,    0, 0, NoSol},
                                            {1, 5, 4,   -1, -4, TwoSol},
                                            {0, 0, 0,    0, 0, Infinite},
                                            {0, 2, 4,   -2, -2, OneSol},
                                            {1, 5, 4,  -40, -10, TwoSol}}; // здесь должен быть фейл

    int n = 0;

    const int ELEMENTS_NUM = sizeof(testArray)/sizeof(testArray[0]);

    for (int i = 0; i < ELEMENTS_NUM; i++) {
        n += solutionTest(testArray[i]); // набор тестов в массиве структур
    }

    return n;
}

bool testInputs(double x1, double x2, double x1ref, double x2ref,
                SolNumber nRoots, SolNumber nRootsRef) {
    return !equals(x1, x1ref) || !equals(x2, x2ref) || nRoots != nRootsRef;
}
