#ifndef __ARGS_H__
#define __ARGS_H__

#include "run_tests.h"

/*! Enum specifying all possible options to run a program*/
enum RunOptions {
    TEST_OPT, /*!< Run unit-tests*/
    HELP_OPT, /*!< Describe all possible command-line arguments*/
    SOLVE_OPT /*!< Run the program normally*/
};

/**
  * @brief Checks. for command-line arguments
  * @param argc Number of command-line arguments
  * @param argv[] Array of all command-line arguments
  * @returns Option which the program should be ran in.
  */
RunOptions checkForCmdArgs(int argc, char* argv[]);

/**
  * @brief Run the application depending on the specified option
  * @param runOption Option which the program should be ran in
  */
void runApplication(RunOptions runOption);

#endif
