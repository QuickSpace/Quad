#include <TXLib.h>
#include "io.h"
#include "utilities.h"
#include "solution.h"
#include "unittest.h"
#include "args.h"

int main(int argc, char* argv[]) {
    double a = 0;
    double b = 0;
    double c = 0;
    double x1 = 0;
    double x2 = 0;
    bool incorrectInput = false;
    RootsNum rootsNumber = OneSol;

    RunOptions runOption = checkForCmdArgs(argc, argv);
    runApp(runOption);

    if (runOption == SOLVE_OPT) {
        do { // не решать уравнение при Help/Test +
            //  возвращать incorrectInput +
            incorrectInput = readCoeffs(&a, &b, &c);  // assert для указателей +
            if(!incorrectInput) {
                rootsNumber = solveSquare(a, b, c, &x1, &x2);
                printRoots(rootsNumber, &x1, &x2);
            }
        } while (declineExit());
    }

    return 0;
}
