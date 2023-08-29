#include "TXLib.h"
#include "run_tests.h"
#include "utilities.h"

void runTestsFromFile(const char* fileName) {
    assert(fileName != nullptr);

    FILE* filePointer = fopen(fileName, "r");

    if (filePointer == NULL) {
        printf("Unable to open %s\n", fileName);
        return;
    }

    printf("Successfully opened %s\n", fileName);

    int testsAmount = getTestsAmount(filePointer);

    int rootsAmount = 0;
    int successCount = 0;

    UnitTest currentTest = {0, 0, 0, 0, 0, NO_SOL};

    for(int i = 0; i < testsAmount; i++) {
        fscanf(filePointer, "%lf %lf %lf %lf %lf %d", &currentTest.a, &currentTest.b,
              &currentTest.c, &currentTest.x1req, &currentTest.x2req, &rootsAmount);
        currentTest.nRootsReq = (RootsNum) rootsAmount;
        successCount += runTest(&currentTest);
    }

    fclose(filePointer);
    printf("Number of successful tests: %d\n", successCount);
}

int getTestsAmount(FILE* filePointer) {
    assert(filePointer != nullptr);

    const int FIELD_AMOUNT = 6;
    double scannedValue = 0;
    int valuesCount = 0;

    while(!feof(filePointer)) {
        fscanf(filePointer, "%lf", &scannedValue);
        valuesCount++;
    }
    fseek(filePointer, 0, SEEK_SET);

    return valuesCount/FIELD_AMOUNT;
}
