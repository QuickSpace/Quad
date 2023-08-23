#ifndef __UNITTEST_H__
#define __UNITTEST_H__

#include "utilities.h"

struct unitStruct {
    double a;
    double b;
    double c;
    double x1ref;
    double x2ref;
    SolNumber nRootsRef;
};

bool testInputs(double x1, double x2, double x1ref, double x2ref,
                SolNumber nRoots, SolNumber nRootsRef);

int solutionTest(struct unitStruct testStruct);

int testAll();

#endif
