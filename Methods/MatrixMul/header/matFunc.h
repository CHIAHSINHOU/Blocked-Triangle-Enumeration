#ifndef __TILED_FUNC_H__
#define __TILED_FUNC_H__

#include<cuda_runtime.h>

typedef unsigned int UI;
#define BIT_PER_ENTRY (sizeof(UI)*8)
#define setEdge(u,v) mat[u*entryNum+(v/BIT_PER_ENTRY)]|=((UI)1<<(v%BIT_PER_ENTRY))
#define getEdge(u,v) (((UI)1<<(v%BIT_PER_ENTRY))&mat[u*entryNum+(v/BIT_PER_ENTRY)])>0

extern __shared__ UI shared[]; // adjMat[entryPerTile*nodeNum], threadTriNum[threadPerBlock]

void inputMat(const char *inFile, UI *mat, int edgeSize, int entryNum);
void matCopyToDevice(int nodeNum, void* mat, void** d_mat);
int cpuCountTriNum(int nodeNum, int nodePerTile, UI *mat);
__global__ void gpuCountTriNum(UI *mat, int *triNum, int nodeNum, int nodePerTile);
__host__ __device__ int countOneBits(UI tar);

#endif
