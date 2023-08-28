#ifndef __SOLUTION_H__
#define __SOLUTION_H__

#include "utilities.h"

/**
  * @brief Solve a quadratic equation
  * @param a - first coefficient
  * @param b - second coefficient
  * @param c - third coefficient
  * @param x1, x2 - pointers to variables roots will be assigned to (for 1 or more solutions)
  * @return The number of solutions
  */
RootsNum solveSquare(double a, double b, double c, double* x1, double* x2);

/**
  * @brief Solve a linear equation bx + c = 0
  * @param b - first coefficient
  * @param c - second coefficient
  * @param x1, x2 - pointers to variables to which the root will be assigned to
  * @return The number of solutions
  */
RootsNum solveLinear(double b, double c, double* x1, double* x2);

#endif
