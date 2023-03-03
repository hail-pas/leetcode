#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void back_track(char *converter[], char **result, char * combination, char * digits, int* index, int com_length, int length){
    if (*digits == '\0') {
        // result[*index] = (char*)malloc(sizeof(char) * com_length);
        result[*index] = combination;
        (*index)++;
    }else {
        // int c_i = 0;
        // while (*(conbination + c_i) != '\0') {
        //     c_i += 1;
        // }
        char head_ch = digits[0];
        char * letters = converter[head_ch - '2'];
        while(*letters != '\0') {
            char * next_combination = (char *)malloc(sizeof(char) * length);
            strcpy(next_combination, combination);
            next_combination[com_length] = *letters;
            next_combination[com_length + 1] = '\0';
            char * next_digits = (char *)malloc(sizeof(char) * length);
            strcpy(next_digits, digits + 1);
            back_track(converter, result, next_combination, next_digits, index, com_length + 1, length);
            letters += 1;
        }
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize){
    char *converter[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int letter_length[] = {3, 3, 3, 3, 3, 4, 3, 4};
    *returnSize = 1;
    int length = 0;
    while (*(digits + length) != '\0') {
        *returnSize *= letter_length[*(digits + length) - '2'];
        length++;
    }
    char ** result = (char **)malloc(sizeof(char *)*(*returnSize));
    char * conbination = (char*)malloc(length*sizeof(char));
    int * initial_index = (int *)malloc(sizeof(int));
    *initial_index = 0;
    back_track( converter, result, conbination, digits, initial_index, 0, length);
    return result;
}


int main(int argc, char *argv[]) {
    int *returnSize = (int *)malloc(sizeof(int));
    char ** result = letterCombinations("23", returnSize);
    for (int i = 0; i < *returnSize ; i++) {
        printf("%s\n", result[i]);
    }
    return 0;
}
