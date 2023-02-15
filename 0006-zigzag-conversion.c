#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * convert(char * s, int numRows){
    if (numRows < 2) {
        return s;
    }

    int length = 0;

    do {
        length++;
    } while (s[length-1] != '\0');

    char *res[numRows];

    for (int i = 0; i < numRows; i++) {
        res[i] = (char *)malloc(length * sizeof(char));
    }

    int i = 0, flag = -1;
    char * c = (char *)malloc(2 * sizeof(char));
    c[1] = '\0';

    while (*s != '\0') {
        c[0] = s[0];
        strcat(res[i], c);
        if (i == 0 || i == numRows - 1) {
            flag = -flag;
        }
        s++;
        i += flag;
    }
    free(c);
    char *result = (char *)malloc(length * sizeof(char));
    for(int i = 0; i < numRows; i++) {
        strcat(result, res[i]);
        free(res[i]);
    }
    return result;
}

int main(int argc, char *argv[]) {
    char *s = "PAYPALISHIRING";
    printf("%s\n", convert(s, 3));
    return 0;
}