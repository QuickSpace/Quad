#ifndef __READ_DATA_H__
#define __READ_DATA_H__

#include <stdio.h>
#include "unit_test.h"

/*! Enum specifying all possible outcomes of opening a file-stream*/
enum OpenFileStatus {
    FILE_OPEN_ERROR = 0, /*!< Unable to open a file*/
    FILE_OPEN_SUCCESS = 1 /*!< File opened successfully*/
};

/**
  * @brief Retrieve all data from a file and use it to run unit-tests
  * @param Pointer to a variable which the number of successful unit-tests should be assigned to
  * @param Name of a file that should be opened
  * @return Outcome of opening a file-stream
  */
OpenFileStatus getTestsFromFile(int* successfulTests, const char* fileName);

/**
  * @brief Get the amount of all individual unit-tests
  * @param Pointer to a file stream
  * @return Amount of all individual unit-tests
  */
int getTestsAmount(FILE* filePointer);;

#endif
