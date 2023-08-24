#include <TXLib.h>
#include "io.h"
#include "utilities.h"
#include "solution.h"
#include "unittest.h"

int main() {
    double a = 0;
    double b = 0;
    double c = 0;
    double x1 = 0;
    double x2 = 0;
    bool incorrectInput = false;
    EqType equationType = OneSol;

    if (confirmTests())
        printf("Number of successful tests: %d\n", runAllTests());

    do {
        //  возвращать incorrectInput +
        incorrectInput = readCoeffs(&a, &b, &c);  // assert для указателей +
        if(!incorrectInput) {
            equationType = solveEq(a, b, c, &x1, &x2);
            printRoots(equationType, &x1, &x2);
        }
    } while (confirmExit());

    return 0;
}
