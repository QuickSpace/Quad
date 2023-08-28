#ifndef __RUN_TESTS_H__
#define __RUN_TESTS_H__

#include <stdio.h>
#include "unit_test.h"

/**
  * @brief Retrieve all data from a file and use it to run unit-tests
  * @param Name of a file that should be opened
  * @return Number of successful tests
  */
int runTestsFromFile(const char* fileName);

/**
  * @brief Get the amount of all individual unit-tests
  * @param Pointer to a file stream
  * @return Amount of all individual unit-tests
  */
int getTestsAmount(FILE* filePointer);

#endif
