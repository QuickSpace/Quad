#ifndef __UNITTEST_H__
#define __UNITTEST_H__

#include "utilities.h"

struct unitTestRef {
    double a;
    double b;
    double c;
    double x1ref;
    double x2ref;
    SolNumber nRootsRef;
};

bool compareValues(double x1, double x2, double x1ref, double x2ref,
                EqType nRoots, EqType nRootsRef);

int runTest(struct unitTestRef* valuesTest);

int testAll();

#endif
