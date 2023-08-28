#ifndef __IO_H__
#define __IO_H__

#include "utilities.h"

/**
  * @brief Reads the user's input of all coefficients
  * @param a - first coefficient
  * @param b - second coefficient
  * @param c - third coefficient
  * @return false only if the input is in the correct format
  */
bool readCoeffs(double* a, double* b, double* c);

/**
  * @brief Outputs all roots of an equation
  * @param Number of roots of the equation
  * @param x1, x2 - pointers to roots' variables
  */
void printRoots(RootsNum rootsNum, double* x1, double* x2);

/**
  * @brief Ask a user to exit the program
  * @return true only if the user refuses to quit
  */
bool declineExit();

#endif
