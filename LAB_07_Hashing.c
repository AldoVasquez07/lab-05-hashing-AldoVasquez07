#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct RandomHashFunction {
    int* fnTable;
};

void initRandomHashFunction(struct RandomHashFunction* randomFn, int M, int n);
void destroyRandomHashFunction(struct RandomHashFunction* randomFn);

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
