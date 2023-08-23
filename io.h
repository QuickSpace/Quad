#ifndef __IO_H__
#define __IO_H__

#include "utilities.h"

// input

bool inputCoeffs(double* a, double* b, double* c);

// output

void outputResult(SolNumber input, double x1, double x2);   // �������� �������� ������� +
    // ����-����� � ��������� ������ +
    // ������� ��� ���������� ����-������ +

// ������������� ������ �� �����

bool confirmTests();
bool confirmExit();

#endif
