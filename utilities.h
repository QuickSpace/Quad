#ifndef __UTILITIES_H__
#define __UTILITIES_H__

enum SolNumber {
    NoSol = 0,
    OneSol = 1,
    TwoSol = 2,
    Infinite = 3
};

bool equals(const double a, const double b);
void clearBuffer();
bool isZero(double a);

#endif
