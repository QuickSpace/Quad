#ifndef __IO_H__
#define __IO_H__

#include "utilities.h"

/**
  * @brief Reads the user's input of all coefficients.
  * @param a First coefficient.
  * @param b Second coefficient.
  * @param c Third coefficient.
  * @returns False only if the input is in the correct format.
  */
bool readCoeffs(double* a, double* b, double* c);

/**
  * @brief Outputs all roots of an equation.
  * @param rootsNum Number of roots of the equation.
  * @param x1 Pointer to root's variable.
  * @param x2 Pointer to root's variable.
  */
void printRoots(RootsNum rootsNum, double* x1, double* x2);

/**
  * @brief Ask a user to exit the program.
  * @returns True only if the user refuses to quit.
  */
bool declineExit();

#endif
