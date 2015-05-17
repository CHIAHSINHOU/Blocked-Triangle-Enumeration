#ifndef __SOLVE_H__
#define __SOLVE_H__

#include "struct.h"

enum{FORWARD = 0, G_FORWARD, MAT, G_MAT, UNDEF};
enum{CPU = 0, GPU};

long long solveBlock(int blockSize, vector< Edge > &edge, int algo=UNDEF);
int scheduler(int nodeNum, int edgeNum);

#endif