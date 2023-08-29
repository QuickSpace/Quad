#ifndef __UTILITIES_H__
#define __UTILITIES_H__

#include "stdio.h"

/*! Enum specifying the number of roots of a quadratic equation*/
enum RootsNum {
    NO_SOL = 0, /*!< No solutions*/
    ONE_SOL = 1, /*!< One solution, used for linear equations*/
    TWO_SOL = 2, /*!< Two solutions*/
    INFINITE_SOL = 3 /*!< Infinitely many solutions*/
};


/**
  * @brief Check whether a and b are equal or not
  * @param a First number
  * @param b Second number
  * @return Result of comparison
  */

bool equals(double a, double b);

/**
  * @brief Clear the buffer of the input stream
  */

void clearBuffer();

/**
  * @brief Check whether a is equal to 0 or not
  * @param a Number to compare 0 to
  * @return Result of comparison
  */

bool isZero(double a);

#endif
