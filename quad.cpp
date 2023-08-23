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
    SolNumber result = OneSol;

    if (confirmTests())
        printf("Number of successful tests: %d\n", testAll());

    do {
        //  возвращать incorrectInput +
        incorrectInput = inputCoeffs(&a, &b, &c);  // assert для указателей +
        if(!incorrectInput) {
            result = solveEq(a, b, c, &x1, &x2);
            outputResult(result, x1, x2);
        }
    } while (confirmExit());

    return 0;
}
