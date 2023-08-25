#ifndef __UTILITIES_H__
#define __UTILITIES_H__

#include "stdio.h"

enum RootsNum {
    NoSol = 0,
    OneSol = 1,
    TwoSol = 2,
    InfiniteSol = 3 // "InfiniteSol" +
};

bool equals(const double a, const double b);
void clearBuffer();
bool isZero(double a);

#endif
