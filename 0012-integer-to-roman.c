#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char * intToRoman(int num){
    if (num < 1 || num > 3999) return 0;
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *roman_strs[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    char *result = (char *)malloc(16 * sizeof(char));
    memset(result, 0, 16);

    for (int i = 0; i < sizeof(values)/sizeof(int); i++) {
        while (num >= values[i]) {
            num -= values[i];
            strcat(result, roman_strs[i]);
        }
    }

    return result;
}

int main(int argc, char *argv[]) {
    int num = 58;
    printf("%s", intToRoman(num));
    return 0;
}
