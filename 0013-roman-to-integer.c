#include <stdio.h>

typedef int (*compare_f)(void *, void *);

int get_index_of_value(void * array, int length, void * v,compare_f f){
    int index = length;
    for (int i = 0; i < length; i++) {
        if (f(&array[i], v) == 1) {
            return i;
        }
    }
    return index;
}

int char_compare(void * left, void * right) {
    char left_ch = *(char *)left;
    char right_ch = *(char *)right;
    if (left_ch == right_ch) {
        return 1;
    }
    return 0;
}

int romanToInt(char * s){
    int values[] = {1000, 500, 100, 50, 10, 5, 1};
    char reprs[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    int result = 0;
    while (*s != '\0') {
        char current_ch = *s;
        char next_ch = *(s+1);
        int curent_roman_index = get_index_of_value(reprs, sizeof(reprs)/sizeof(char), &current_ch, char_compare);
        if (curent_roman_index == sizeof(reprs)/sizeof(char)) {
            return 0;
        }
        int next_roman_index = get_index_of_value(reprs, sizeof(reprs)/sizeof(char), &next_ch, char_compare);
        if (next_ch != '\0' && next_roman_index != sizeof(reprs)/sizeof(char) && values[curent_roman_index] < values[next_roman_index]) {
            result -= values[curent_roman_index];
        }else {
            result += values[curent_roman_index];
        }
        s++;
    }
    return result;
}


int main(int argc, char *argv[]) {
    printf("%d", romanToInt("MCMXCIV"));
    return 0;
}
