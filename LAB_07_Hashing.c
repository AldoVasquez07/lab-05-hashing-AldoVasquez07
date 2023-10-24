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

struct HashTable* createHashTable(int h, int n) {
    struct HashTable* table = (struct HashTable*)malloc(sizeof(struct HashTable));
    table->miAtributo = h;
    table->bucket = (int**)malloc(n * sizeof(int*));
    initRandomHashFunction(&(table->hashFunction), n, n);

    for (int i = 0; i < n; i++) {
        table->bucket[i] = NULL;
    }

    return table;
}

int mi_Mod(int x, int n) {
    return x % n;
}

void insert(struct HashTable* table, int x) {
    int index = table->hashFunction.fnTable[x];
    int* newList = NULL;
    int length = 0;

    if (table->bucket[index] == NULL) {
        newList = (int*)malloc(2 * sizeof(int));
        newList[0] = x;
        newList[1] = -1;
    } else {
        while (table->bucket[index][length] != -1) {
            length++;
        }
        newList = (int*)malloc((length + 2) * sizeof(int));

        for (int i = 0; i < length; i++) {
            newList[i] = table->bucket[index][i];
        }
        newList[length] = x;
        newList[length + 1] = -1;
        free(table->bucket[index]);
    }

    table->bucket[index] = newList;
}

void removeItem(struct HashTable* table, int x) {
    int index = table->hashFunction.fnTable[x];
    if (table->bucket[index] != NULL) {
        int length = 0;
        while (table->bucket[index][length] != -1) {
            length++;
        }

        int* newList = (int*)malloc((length - 1) * sizeof(int));
        int i = 0;
        int j = 0;

        while (i < length) {
            if (table->bucket[index][i] != x) {
                newList[j] = table->bucket[index][i];
                j++;
            }
            i++;
        }

        free(table->bucket[index]);
        if (j > 0) {
            newList[j] = -1;
            table->bucket[index] = newList;
        } else {
            table->bucket[index] = NULL;
        }
    }
}


int main()
{
    cout<<"Hello World";

    return 0;
}
