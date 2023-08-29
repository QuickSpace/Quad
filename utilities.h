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
  * @brief Check whether a and b are equal or not
  * @param a First number
  * @param b Second number
  * @returns Result of comparison
  */

bool equals(double a, double b);

/**
  * @brief Clear the buffer of the input stream
  */

void clearBuffer();

/**
  * @brief Check whether a is equal to 0 or not
  * @param a Number to compare 0 to
  * @returns Result of comparison
  */

bool isZero(double a);

#endif
