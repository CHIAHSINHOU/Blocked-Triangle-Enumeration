#include<cstdio>
#include<cstdlib>

bool edge[10000][10000];

int main(int argc, char *argv[]){
    if(argc != 4){
        fprintf(stderr, "usage: bruteForce <input_path> < node_num> <edge_num>\n");
        return 0;
    }

    int nodeNum = atoi(argv[2]);
    int edgeNum = atoi(argv[3]);

    FILE *fp = fopen(argv[1], "r");
    if(nodeNum > 10000){
        fprintf(stderr, "too many nodes\n");
        return 0;
    }

    for(int i = 0; i < edgeNum; i++){
        int u, v;
        fscanf(fp, "%d%d", &u, &v);
        edge[u][v] = edge[v][u] = true;
    }
    fclose(fp);
    int triNum = 0;
    for(int i = 0; i < nodeNum; i++){
        for(int j = i+1; j < nodeNum; j++){
            if(!edge[i][j]) continue;
            for(int k = j+1; k < nodeNum; k++){
                if(edge[j][k] && edge[k][i]){
                    triNum++;
                    printf("%d %d %d\n", i, j, k);
                }
            }
        }
    }
    fprintf(stderr, "total triangle: %d\n", triNum);

    return 0;
}
