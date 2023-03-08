#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// typedef enum bool {false, true} bool;

struct MyListNode {
    void *val;
    struct MyListNode *next;
};

struct Stack {
    struct MyListNode* head;
    int size;
    void * push;
    void * pop;
    // void (*push)(struct Stack, void *value);
    // void *(*pop)(struct Stack, void *value);
};

typedef void (*int_push_f)(struct Stack *, int value);
typedef void (*int_pop_f)(struct Stack *, int *value);

void int_push(struct Stack * sp, int value){
    struct MyListNode* temp = (struct MyListNode*)malloc(sizeof(struct MyListNode));
    temp->val = malloc(sizeof(int));
    *(int *)temp->val = value;
    temp->next = sp->head;
    if (!sp->head){
        sp->head = temp;
    };
    sp->size++;
}

void int_pop(struct Stack * sp, int * value) {
    if (sp->size == 0) {
        value = NULL;
        return;
    }
    struct MyListNode* temp = sp->head;
    value = temp->val;
    free(temp->val);
    free(temp);
    sp ->head = sp ->head->next;
    sp->size--;
}

bool isValid(char * s){
    // struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    // stack->push = int_push;
    // stack->pop = int_pop;
    // int * temp = malloc(sizeof(int));
    int length = strlen(s);
    int top = 0;
    int stack[length];
    while (*s) {
        // if (stack->size > 0 && (*s - *(int *)stack->head->val == 1 || *s - *(int *)stack->head->val == 2)) {
        //     ((int_pop_f)stack->pop)(stack, temp);
        // }else {
        //     ((int_push_f)stack->push)(stack, (int)*s);
        // }
        if (top != 0 && (*s - stack[top - 1] == 1 || *s - stack[top - 1] == 2)) {
            top--;
        }else {
            stack[top++] = *s;
        }
        s++;
    }
    return top == 0;
}

int main(int argc, char *argv[]) {
    char *s = "()";
    printf("%s\n", isValid(s) ? "true" : "false");
    return 0;
}
