#include <TXLib.h>
#include "io.h"
#include "utilities.h"
#include "solution.h"
#include "unit_test.h"
#include "args.h"

// "main.cpp" +

int main(int argc, char* argv[]) {
    RunOptions runOption = checkForCmdArgs(argc, argv);
    runApplication(runOption);

    return 0;
}
