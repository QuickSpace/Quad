#ifndef __UTILITIES_H__
#define __UTILITIES_H__

#include "stdio.h"

/*! Enum specifying the number of roots of a quadratic equation*/
enum RootsNum {
    NoSol = 0, /*!< No solutions*/
    OneSol = 1, /*!< One solution, used for linear equations*/
    TwoSol = 2, /*!< Two solutions*/
    InfiniteSol = 3 /*!< Infinitely many solutions*/
};


/**
  * @brief Check whether a and b is equal or not
  * @param a - first number
  * @param b - second number
  * @return result of comparison
  */

bool equals(const double a, const double b);

/**
  * @brief Clear the buffer of the input-output stream
  */

void clearBuffer();

/**
  * @brief Check whether a is equal to 0 or not
  * @param a - number to compare 0 to
  * @return result of comparison
  */

bool isZero(double a);

#endif
