#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#define N 1000

typedef struct {
    int values[N];
    int value_to_index_map[N];
    size_t size;
} RandomizedSet;

RandomizedSet* randomizedSetCreate() {
    RandomizedSet *set = calloc(1, sizeof(RandomizedSet));
    for (int i = 0; i < N; i++) {
        set->value_to_index_map[i] = -1;
    }
    srand(time(NULL));
    return set;
}

bool randomizedSetInsert(RandomizedSet* obj, int val) {
    if (obj->value_to_index_map[val] == -1) {
        obj->values[obj->size] = val;
        obj->value_to_index_map[val] = obj->size;
        obj->size += 1;
        return true;
    }
    return false;  
}

bool randomizedSetRemove(RandomizedSet* obj, int val) {
    if (obj->value_to_index_map[val] != -1){
        obj->value_to_index_map[obj->values[obj->size-1]] = obj->value_to_index_map[val];
        obj->value_to_index_map[val] = -1;
        obj->values[val] = obj->values[obj->size-1];
        obj->size--;
        return true;    
    }
    return false;
    
}

int randomizedSetGetRandom(RandomizedSet* obj) {
    return obj->values[(int)rand()];
}

void randomizedSetFree(RandomizedSet* obj) {
    free(obj);    
}

/**
 * Your RandomizedSet struct will be instantiated and called as such:
 * RandomizedSet* obj = randomizedSetCreate();
 * bool param_1 = randomizedSetInsert(obj, val);
 
 * bool param_2 = randomizedSetRemove(obj, val);
 
 * int param_3 = randomizedSetGetRandom(obj);
 
 * randomizedSetFree(obj);
*/
