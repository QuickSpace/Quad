#include <TXLib.h>
#include "io.h"
#include "utilities.h"
#include "solution.h"
#include "unit_test.h"
#include "args.h"
#include <unistd.h>

const char helpCmdArg = 'h';
const char testsCmdArg = 't';
const char arguments[] = {helpCmdArg, testsCmdArg};

RunOptions checkForCmdArgs(int argc, char* argv[]) {
    int currentArg = 0;
    while (currentArg != -1) {
        currentArg = getopt(argc, argv, arguments);
        if (currentArg == helpCmdArg)
            return HELP_OPT;
        if (currentArg == testsCmdArg)
            return TEST_OPT;
    }

    return SOLVE_OPT;
}

void runApplication(RunOptions runOption) {
    switch (runOption) {
        case TEST_OPT:
        {
            int testsNum = 0;
            const char* fileName = "tests.txt";
            switch((OpenFileStatus) getTestsFromFile(&testsNum, fileName)) {
                case FILE_OPEN_SUCCESS:
                    printf("Successfully opened %s\n", fileName);
                    break;
                case FILE_OPEN_ERROR:
                    printf("Unable to open %s\n", fileName);
                    break;
                default:
                    assert(0 && "Unknown opening file status!\n");
                    break;
            }
            printf("Number of successful tests: %d\n", testsNum);
            break;
        }
        case HELP_OPT:
            printf("Quadratic equation solver.\n"
                "Options: \n"
                "\t -%c - running tests\n"
                "\t -%c - print help\n", testsCmdArg, helpCmdArg);
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
