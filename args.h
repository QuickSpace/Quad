#ifndef __ARGS_H__
#define __ARGS_H__

#include "readdata.h"

enum RunOptions {
    TEST_OPT,
    HELP_OPT,
    SOLVE_OPT
};

RunOptions checkForCmdArgs(int argc, char* argv[]);
void runApp(RunOptions argType);

#endif
