#include <TXLib.h>
#include "io.h"
#include "utilities.h"
#include "solution.h"
#include "unit_test.h"
#include "args.h"

int main(int argc, char* argv[]) {
    RunOptions runOption = checkForCmdArgs(argc, argv);

    switch (runOption) {
        case TEST_OPT:
            runTestMode();
            break;
        case HELP_OPT:
            runHelpMode();
            break;
        case SOLVE_OPT:
            runSolveMode();
            break;
        default:
            assert(0 && "Unknown running option!");
            break;
    }

    return 0;
}
