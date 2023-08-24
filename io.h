#ifndef __IO_H__
#define __IO_H__

#include "utilities.h"

// input

bool readCoeffs(double* a, double* b, double* c);

// output

void printRoots(RootsNum eqType, double* x1, double* x2);   // �������� �������� ������� +
    // ����-����� � ��������� ������ +
    // ������� ��� ���������� ����-������ +

// ������������� ������ �� �����

bool declineExit();

#endif
