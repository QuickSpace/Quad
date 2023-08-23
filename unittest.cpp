#include <TXLib.h>
#include "unittest.h"
#include "solution.h"
#include "utilities.h"

int solutionTest(double a, double b, double c,
                 double x1ref, double x2ref, SolNumber nRootsRef) {
    double x1 = 0, x2 = 0;
    SolNumber nRoots = solveEq(a, b, c, &x1, &x2);

    if(!equals(x1, x1ref) || !equals(x2, x2ref) || nRoots != nRootsRef) {  // условие в одну функцию
        printf("FAILED: x1: %lf, x2: %lf, # of roots: %d; \n"
               "Expected: x1ref = %lf, x2ref = %lf, # of roots: %d\n",
            x1, x2, (int) nRoots, x1ref, x2ref, (int) nRootsRef);
        return 0;
    }

    printf("Successful\n");
    return 1;
}

int testAll() {
    int n = 0;
    n += solutionTest(4, 4, 1, -0.5, -0.5, OneSol);
    n += solutionTest(9, 1, 8, 0, 0, NoSol);
    n += solutionTest(1, 5, 4, -1, -4, TwoSol);
    n += solutionTest(0, 0, 0, 0, 0, Infinite); // набор тестов в массиве структур
    n += solutionTest(1, 5, 4, -40, -10, TwoSol); // здесь должен быть фейл

    return n;
}
