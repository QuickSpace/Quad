#include <TXLib.h>
#include <unistd.h>
#include "io.h"
#include "utilities.h"
#include "solution.h"
#include "unit_test.h"
#include "args.h"

static const char HELP_CMD_ARG = 'h';
static const char TESTS_CMD_ARG = 't';
static const char ARG_REQ = ':';

static char CMD_ARGS[] = {HELP_CMD_ARG, TESTS_CMD_ARG, ARG_REQ};

RunOptions checkForCmdArgs(int argc, char* argv[]) {
    assert(argv != nullptr);

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
            const char* DEFAULT_PATH = "tests/tests.txt";
            const char* DEFAULT_PATH_ARG = "default";

            if (optarg == NULL || strcmp(optarg, DEFAULT_PATH_ARG) == 0)
                runTestsFromFile(DEFAULT_PATH);
            else
                runTestsFromFile(optarg);

            break;
        }
        case HELP_OPT:
            printf("Quadratic equation solver.\n"
                   "Options: \n"
                   "\t -%c - running tests\n"
                   "\t -%c - print help\n",
                   TESTS_CMD_ARG,
                   HELP_CMD_ARG);
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
            RootsNum rootsNumber = ONE_SOL;

            do {
                incorrectInput = readCoeffs(&a, &b, &c);
                if(!incorrectInput) {
                    rootsNumber = solveSquare(a, b, c, &x1, &x2);
                    printRoots(rootsNumber, &x1, &x2);
                }
            } while (!confirmExit());

            break;
        }
        default:
            assert(!"Unknown argument!");
            break;
    }
}
