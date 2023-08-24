#include <TXLib.h>
#include "args.h"
#include "unittest.h"
#include <unistd.h>

const char arguments[] = {'t', 'h'};

void checkForArgs(int argc, char* argv[]) {
    // константы для команд +
    int currentArg = 0;
    while (currentArg != -1) {
        currentArg = getopt(argc, argv, arguments); // <- сюда добавлять команды
        if (currentArg == arguments[0]) {
            useArgs(Tests);
            return;
        }
        if (currentArg == arguments[1]) {
            useArgs(Help);
            return;
        }
    }

    useArgs(None); // в отдельную функцию и файл +
}

void useArgs(ArgsType argType) {
    switch (argType) {
        case Tests:
            printf("Number of successful tests: %d\n", runAllTests());
            break;
        case Help:
            printf("Quadratic equation solver.\n"
                "Options: \n"
                "\t -%c - running tests\n"
                "\t -%c - print help\n", arguments[0], arguments[1]);
            break;
        case None:
            printf("Description: A program designed to solve quadratic equations\n");
            break;
        default:
            assert(0 && "Unknown argument!");
            break;
    }
}
