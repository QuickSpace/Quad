#ifndef __ARGS_H__
#define __ARGS_H__

enum ArgsType {
    Tests,
    Help,
    None
};

void checkForArgs(int argc, char* argv[]);
void useArgs(ArgsType argType);

#endif
