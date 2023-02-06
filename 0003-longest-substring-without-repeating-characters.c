
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int subchr_index(char *s_start, int length, char c){
    for (int i = 0; i < length; i++) {
        if (*(s_start + i) == c) {
            return i;
        }
    }
    return -1;
}

int lengthOfLongestSubstring(char * s){
    int max_length = 0, offset = 0;
    char *window_start = s;
    while (*s!='\0') {
        int found_index = subchr_index(window_start, offset, *s);
        if (found_index != -1) {
            window_start += found_index + 1;
            offset -= found_index;
        }
        else {
            offset++;
        }
        max_length = (s - window_start + 1) > max_length? (s - window_start + 1): max_length;
        s++;
    }

    return max_length;
}

int main(int argc, char *argv[]){
    char * s = "pwwkew";
    printf("Length: %d", lengthOfLongestSubstring(s));
    return 0;
}