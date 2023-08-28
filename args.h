#ifndef __ARGS_H__
#define __ARGS_H__

#include "read_data.h"

/*! Enum specifying all possible options to run a program*/
enum RunOptions {
    TEST_OPT, /*!< Run unit-tests*/
    HELP_OPT, /*!< Describe all possible command-line arguments*/
    SOLVE_OPT /*!< Run the program normally*/
};

/**
  * @brief Check for command-line arguments
  * @return Option which the program should be ran in
  */
RunOptions checkForCmdArgs(int argc, char* argv[]);

/**
  * @brief Run the application depending on the specified option
  * @param Option which the program should be ran in
  */
void runApplication(RunOptions argType);

#endif
