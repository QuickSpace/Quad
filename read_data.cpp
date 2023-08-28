#include "TXLib.h"
#include "read_data.h"
#include "utilities.h"

OpenFileStatus getTestsFromFile(int* successfulTests, const char* fileName) {
    FILE* filePointer = fopen(fileName, "r");

    if (filePointer == NULL)
        return FILE_OPEN_ERROR;

    int structSize = sizeof(UnitTest);
    int testsAmount = getTestsAmount(filePointer);

    UnitTest* testsPtr = (UnitTest*) calloc(testsAmount, structSize * (testsAmount));

    int rootsAmount = 0;
    fseek(filePointer, 0, SEEK_SET);
    UnitTest* loopPtr;

    for(int i = 0; i < testsAmount; i++) {
        loopPtr = testsPtr + i;
        fscanf(filePointer, "%lf %lf %lf %lf %lf %d", &loopPtr -> a, &loopPtr -> b,
              &loopPtr -> c, &loopPtr -> x1req, &loopPtr -> x2req, &rootsAmount);
        (loopPtr -> nRootsReq) = (RootsNum) rootsAmount;
        runTest(loopPtr, successfulTests);
    }

    fclose(filePointer);
    free(testsPtr);
    return FILE_OPEN_SUCCESS;
}

int getTestsAmount(FILE* filePointer) {
    const int fieldAmount = 6;
    double scannedValue = 0;
    int testsAmount = 0;
    while(!feof(filePointer)) {
        fscanf(filePointer, "%lf", &scannedValue);
        testsAmount++;
    }
    return testsAmount/fieldAmount;
}
