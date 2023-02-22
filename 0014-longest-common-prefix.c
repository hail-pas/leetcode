#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0) {
        return "";
    }
    char * result = NULL;
    int i = 0, j = 1;
    while (*(strs[0] + i) != '\0') {
        char ch = *(strs[0] + i);
        for (j = 1; j < strsSize; j++) {
            int compare_str_length = 0;
            while (strs[j][compare_str_length] != '\0') {
                compare_str_length++;
            }
            if (compare_str_length < i + 1 || strs[j][i] != strs[0][i]) {
                return result;
            }
        }
        result = realloc(result, i + 2);
        strcat(result, &strs[0][i]);
        result[i + 1] = '\0';
        i++;
    }
    result = realloc(result, i + 2);
    strcat(result, "\0");
    return result;
}

int main(int argc, char *argv[]) {
    char ** strs = malloc(3 * sizeof(char *));
    char *flower = "flower";
    char *flow = "flow";
    char *flight = "flight";
    strs[0] = flower;
    strs[1] = flow;
    strs[2] = flight;

    printf("%s\n", longestCommonPrefix((char **)strs, 3));
    return 0;
}
