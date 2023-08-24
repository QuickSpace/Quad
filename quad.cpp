#include <TXLib.h>
#include <unistd.h>
#include "io.h"
#include "utilities.h"
#include "solution.h"
#include "unittest.h"

int main(int argc, char* argv[]) {
    double a = 0;
    double b = 0;
    double c = 0;
    double x1 = 0;
    double x2 = 0;
    bool incorrectInput = false;
    EqType equationType = OneSol;

    int currentArg = 0;
    while (currentArg != -1) {
        currentArg = getopt(argc, argv, "t"); // <- сюда добавлять команды

        if(currentArg == 't')
            printf("Number of successful tests: %d\n", runAllTests());
    }

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
