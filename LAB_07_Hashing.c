#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct RandomHashFunction {
    int* fnTable;
};

void initRandomHashFunction(struct RandomHashFunction* randomFn, int M, int n) {
    randomFn->fnTable = (int*)malloc(M * sizeof(int));
    srand(time(NULL));

    for (int x = 0; x < M; x++) {
        randomFn->fnTable[x] = rand() % n;
    }
}

void destroyRandomHashFunction(struct RandomHashFunction* randomFn) {
    free(randomFn->fnTable);
}


struct HashTable {
    int miAtributo;
    int** bucket;
    struct RandomHashFunction hashFunction;
};



int main()
{
    cout<<"Hello World";

    return 0;
}
