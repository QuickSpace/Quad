#include "TXLib.h"
#include "readdata.h"
#include "utilities.h"

UnitTest* getTestsFromFile(int* testsAmount) {
    const char* fileName = "tests.txt";
    FILE* filePointer;

    if ((filePointer = fopen(fileName, "r")) == NULL) {
        printf("Unable to open %s", fileName);
        getchar();
        fclose(filePointer);
    }

    int structSize = sizeof(UnitTest);
    *testsAmount = getTestsAmount(filePointer);

    UnitTest* testsPtr = (UnitTest*) calloc(*testsAmount, structSize * (*testsAmount));

    int rootsAmount = 0;
    fseek(filePointer, 0, SEEK_SET);
    UnitTest* loopPtr;
    for (int i = 0; i < *testsAmount; i++) {
        loopPtr = testsPtr + i;
        fscanf(filePointer, "%lf %lf %lf %lf %lf %d", &(loopPtr -> a), &(loopPtr -> b),
              &(loopPtr -> c), &(loopPtr -> x1req), &(loopPtr -> x2req), &rootsAmount);
        (loopPtr -> nRootsReq) = getRootsNum(rootsAmount);
        printf("%lf %lf %lf %lf %lf %d\n", (loopPtr -> a), (loopPtr -> b),
              (loopPtr -> c), (loopPtr -> x1req), (loopPtr -> x2req), getRootsNum(rootsAmount));
    }

    fclose(filePointer);
    return testsPtr;
}

RootsNum getRootsNum(int rootsAmount) {
    switch (rootsAmount) {
    case 0:
        return NoSol;
        break;
    case 1:
        return OneSol;
        break;
    case 2:
        return TwoSol;
        break;
    case 3:
        return InfiniteSol;
        break;
    default:
        assert(0 && "Unknown number of roots!");
        break;
    }

    return NoSol;
}

int getTestsAmount(FILE* filePointer) {
    double scannedValue = 0;
    int testsAmount = 0;
    while(!feof(filePointer)) {
        fscanf(filePointer, "%lf", &scannedValue);
        testsAmount++;
    }
    return testsAmount/fieldAmount;
}
