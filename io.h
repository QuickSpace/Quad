#ifndef __IO_H__
#define __IO_H__

#include "utilities.h"

// input

bool readCoeffs(double* a, double* b, double* c);

// output

void printRoots(EqType eqType, double x1, double x2);   // поменять название функции +
    // юнит-тесты в отдельном модуле +
    // условие для выполнения юнит-тестов +

// подтверждение выхода из проги

bool confirmTests();
bool confirmExit();

#endif
