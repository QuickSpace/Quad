#ifndef __SOLUTION_H__
#define __SOLUTION_H__

#include "utilities.h"

/**
  * @brief Solve a quadratic equation
  * @param a First coefficient
  * @param b Second coefficient
  * @param c Third coefficient
  * @param x1 Pointer to a variable which the first root will be assigned to (for 1 or more solutions)
  * @param x2 Pointer to a variable which the second root will be assigned to (for 1 or more solutions)
  * @return The number of solutions
  */
RootsNum solveSquare(double a, double b, double c, double* x1, double* x2);

/**
  * @brief Solve a linear equation bx + c = 0
  * @param b First coefficient
  * @param c Second coefficient
  * @param x1 Pointer to a variable which the first root will be assigned too
  * @param x2 Pointer to a variable which the first root will be assigned too
  * @return The number of solutions
  */
RootsNum solveLinear(double b, double c, double* x1, double* x2);

#endif
