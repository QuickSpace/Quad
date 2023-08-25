#ifndef __READDATA_H__
#define __READDATA_H__

#include <stdio.h>
#include "unittest.h"
#include "readdata.h"

const int fieldAmount = 6;

UnitTest* getTestsFromFile(int* testsAmount);
int getTestsAmount(FILE* filePointer);
RootsNum getRootsNum(int rootsAmount);

#endif
