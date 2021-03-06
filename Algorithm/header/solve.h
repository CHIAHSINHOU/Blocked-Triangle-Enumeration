#ifndef __SOLVE_H__
#define __SOLVE_H__

#include "block.h"
#include "listArray.h"
#include <vector>

using std::vector;

enum{LIST = 0, G_LIST, MAT, G_MAT, UNDEF};
enum{CPU = 0, GPU};

long long findTriangle(const ListArrMatrix &block, const vector< int > &rowWidth, int blockDim);
void scheduler(const ListArray &edge, const ListArray &target, int width, bool isDiagonal);
void getStrategy(const ListArray &edge, const ListArray &target, int width, bool isDiagonal, int &device, int &proc);

#endif
