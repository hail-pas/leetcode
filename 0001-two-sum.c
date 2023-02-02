#include <malloc/malloc.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

typedef struct int2int_hash_node Int2IntHashNode;
struct int2int_hash_node {
    int key;
    int *vals;  // collision, default: [&val, 0x00]
    Int2IntHashNode *next;
} ;

typedef struct int2int_hashtable Int2IntHashtable;

struct int2int_hashtable {
    Int2IntHashNode * items;
    // int size;
    int count;
    void (*hanle_collision)(Int2IntHashtable *, int k, int cuurent_val, int *val);
};

inline static uint64_t hash(const int key) {
    // simple hash func
    return key;
};

void add_element(Int2IntHashtable * hashtable, const int key, const int value) {
    int hashed_key = hash(key);
    Int2IntHashNode * temp = hashtable->items;
    Int2IntHashNode * previous = hashtable->items;
    for (; temp; temp = temp->next) {
        previous = temp;
        if (temp->key == hashed_key) {
            // collision
            // hashtable->hanle_collision(hashtable, hashed_key, value, temp->vals);
            int *last_val = temp -> vals;
            int length = 1;
            while (*last_val) {
                last_val++;
                length++;
            }
            temp->vals = (int*)realloc(temp->vals, length+1);
            *last_val = value;
            int *set_null = last_val+1;
            set_null = 0x0;
            return;
        }
    }
    Int2IntHashNode *current = (Int2IntHashNode *)malloc(sizeof(Int2IntHashNode));
    current->key = key;
    int *cuurent_vals = (int *)malloc(sizeof(int) * 2);
    *cuurent_vals = value;
    int *set_null = cuurent_vals+1;
    set_null = 0x0;
    current->vals = cuurent_vals;
    current->next = NULL;
    if (previous) {
        // 存在最后一个节点
        previous->next = current;
        hashtable->count++;
    } else {
        // 不存在节点
        hashtable->items = current;
        hashtable->count = 1;
    }
    return;
};

Int2IntHashNode* search_element(const Int2IntHashtable * const hashtable, const int key) {
    int hashed_key = hash(key);
    Int2IntHashNode * finded = hashtable->items;
    for (; finded; finded = finded->next) {
        if(finded->key == hashed_key){
            break;
        }
    }
    return finded;
};

// void delete_element(Int2IntHashtable * hashtable, const int key) {

// };

void print_hashtable(const Int2IntHashtable * const hashtable){
    Int2IntHashNode * temp = hashtable->items;
    for (; temp; temp = temp->next) {
        printf("Key: %d, ", temp->key);
        int *last_val = temp -> vals;
        printf("Values: ");
        while (*last_val) {
            printf("\t%d", *last_val);
            last_val++;
        }
        printf("\n");
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i;
    int *result=NULL;
    Int2IntHashtable hashtable = {};
    Int2IntHashNode *finded = NULL;
    *returnSize=2;
    for(i=0;i<numsSize-1;i++)
    {
        if ((finded=search_element(&hashtable, target - nums[i]))) {
            result=(int*)malloc(sizeof(int)*2);
            result[0]=*finded->vals;
            result[1]=i;
            break;
        }
        add_element(&hashtable, nums[i], i);
    }
    return result;
}


int main(int argc, char *argv[]) {
    // Int2IntHashtable hashtable = {};
    // add_element(&hashtable, 10, 10 * 2);
    // add_element(&hashtable, 20, 20 * 2);
    // add_element(&hashtable, 20, 20 * 2 + 1);
    // add_element(&hashtable, 20, 20 * 2 + 2);
    // add_element(&hashtable, 30, 30 * 2);
    // add_element(&hashtable, 40, 40 * 2);
    // add_element(&hashtable, 40, 40 * 2 + 1);
    // print_hashtable(&hashtable);
    clock_t start,end;
    start = clock();
    int nums[] = {1, 2, 3, 4, 4, 6, 7};
    int returnsize = 2;
    int *result = NULL;
    result = twoSum(nums, 7, 9, &returnsize);
    if (result) {
        printf("Foud: [%d, %d]\n", result[0], result[1]);
    } else {
        printf("Not Found\n");
    }
    result = twoSum(nums, 7, 11, &returnsize);
    if (result) {
        printf("Foud: [%d, %d]\n", result[0], result[1]);
    } else {
        printf("Not Found\n");
    }
    result = twoSum(nums, 7, 8, &returnsize);
    if (result) {
        printf("Foud: [%d, %d]\n", result[0], result[1]);
    } else {
        printf("Not Found\n");
    }
    end=clock();
    printf("totile time=%lf ms\n",(double)(end-start)*1000.0/CLOCKS_PER_SEC);
    return 0;
}