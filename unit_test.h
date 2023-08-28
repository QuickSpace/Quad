#ifndef __UNIT_TEST_H__
#define __UNIT_TEST_H__

#include "utilities.h"

/*! Structure required to perform a unit-test*/
struct UnitTest {
    double a; /*!< First coefficient*/
    double b; /*!< Second coefficient*/
    double c; /*!< Third coefficient*/
    double x1req; /*!< Required first root*/
    double x2req;/*!< Required second root*/
    RootsNum nRootsReq;/*!< Required number of roots*/
};

/**
  * @brief Run a unit-test
  * @param Pointer to a structure containing values for a single test
  * @return 1 if test succeeded, 0 if failed
  */
int runTest(const UnitTest* valuesTest);

#endif

