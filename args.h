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
  * @brief Checks for command-line arguments
  * @param argc Number of command-line arguments
  * @param argv[] Array of all command-line arguments
  * @return Option which the program should be ran in
  */
RunOptions checkForCmdArgs(int argc, char* argv[]);

/**
  * @brief Run all unit-tests
  */
void runTestMode();

/**
  * @brief Display all command-line options
  */
void runHelpMode();

/**
  * @brief Run the program normally
  */
void runSolveMode();

#endif
