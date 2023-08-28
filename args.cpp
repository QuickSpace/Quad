#include <TXLib.h>
#include "io.h"
#include "utilities.h"
#include "solution.h"
#include "unit_test.h"
#include "args.h"
#include <unistd.h>

const char HELP_CMD_ARG = 'h';
const char TESTS_CMD_ARG = 't';

const char ARG_REQ = ':';

const char CMD_ARGS[] = {HELP_CMD_ARG, TESTS_CMD_ARG, ARG_REQ};

RunOptions checkForCmdArgs(int argc, char* argv[]) {
    int currentArg = 0;
    while (currentArg != -1) {
        currentArg = getopt(argc, argv, CMD_ARGS);
        if (currentArg == HELP_CMD_ARG)
            return HELP_OPT;
        if (currentArg == TESTS_CMD_ARG)
            return TEST_OPT;
    }

    return SOLVE_OPT;
}

void runApplication(RunOptions runOption) {
    switch (runOption) {
        case TEST_OPT:
        {
            int testsNum = 0;
            const char* defaultDir = "tests/tests.txt";

            if(optarg != NULL)
                testsNum = runTestsFromFile(optarg);
            else
                testsNum = runTestsFromFile(defaultDir);

            printf("Number of successful tests: %d\n", testsNum);
            break;
        }
        case HELP_OPT:
            printf("Quadratic equation solver.\n"
                "Options: \n"
                "\t -%c - running tests\n"
                "\t -%c - print help\n",
                TESTS_CMD_ARG, HELP_CMD_ARG);
            break;
        case SOLVE_OPT:
        {
            printf("Description: A program designed to solve quadratic equations\n");

            double a = 0;
            double b = 0;
            double c = 0;
            double x1 = 0;
            double x2 = 0;
            bool incorrectInput = false;
            RootsNum rootsNumber = OneSol;

            do {
                incorrectInput = readCoeffs(&a, &b, &c);
                if(!incorrectInput) {
                    rootsNumber = solveSquare(a, b, c, &x1, &x2);
                    printRoots(rootsNumber, &x1, &x2);
                }
            } while (declineExit());

            break;
        }
        default:
            assert(0 && "Unknown argument!");
            break;
    }
}
