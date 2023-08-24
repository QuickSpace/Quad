#include <TXLib.h>
#include "args.h"
#include "unittest.h"
#include <unistd.h>

// в отдельные константы +
const char helpCmdArg = 'h';
const char testsCmdArg = 't';
const char arguments[] = {helpCmdArg, testsCmdArg};

RunOptions checkForCmdArgs(int argc, char* argv[]) { // "checkForCmdArgs", возвращать enum +
    // константы для команд +
    int currentArg = 0;
    while (currentArg != -1) {
        currentArg = getopt(argc, argv, arguments); // <- сюда добавлять команды
        if (currentArg == helpCmdArg) // константы писать капсом +
            return HELP_OPT;
        if (currentArg == testsCmdArg)
            return TEST_OPT;
    }

    return SOLVE_OPT; // в отдельную функцию и файл +
}

void runApp(RunOptions runOption) { // "runApp" +
    switch (runOption) {
        case TEST_OPT:  // "TEST_OPT" +
            printf("Number of successful tests: %d\n", runAllTests());
            break;
        case HELP_OPT:  // "HELP" +
            printf("Quadratic equation solver.\n"
                "Options: \n"
                "\t -%c - running tests\n"
                "\t -%c - print help\n", arguments[0], arguments[1]);
            break;
        case SOLVE_OPT: // "SOLVE_OPT" +
            printf("Description: A program designed to solve quadratic equations\n");
            break;
        default:
            assert(0 && "Unknown argument!");
            break;
    }
}
