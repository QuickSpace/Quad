#ifndef __UNITTEST_H__
#define __UNITTEST_H__

#include "utilities.h"

struct UnitTest {
    double a;
    double b;
    double c;
    double x1req;
    double x2req;
    RootsNum nRootsReq;
};

bool checkValues(double x1, double x2, double x1req, double x2req,
                RootsNum nRoots, RootsNum nRootsReq);

int runTest(const UnitTest* valuesTest);

int runAllTests();

#endif
