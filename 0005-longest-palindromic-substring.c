#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char * longestPalindrome(char * s){
    int n = strlen(s);
    int d1[n], d2[n];

    for (int i = 0; i < n; i++) {
        d1[i] = 1;
        while (i - d1[i] >= 0 && 1 + d1[i] < n && s[i-d1[i]] == s[i + d1[i]]) {
            d1[i]++;
        }
        d2[i] = 0;
        while (i - d2[i] - 1 >= 0 && 1 + d2[i] < n && s[i-d2[i]-1] == s[i + d2[i]]) {
            d2[i]++;
        }
    }

    int d1_max = 0, d1_max_index = 0, d2_max = 0, d2_max_index = 0;

    for (int i = 0; i<n; i++){
        if (d1_max < d1[i]) {
            d1_max = d1[i];
            d1_max_index = i;
        }
        if (d2_max < d2[i]) {
            d2_max = d2[i];
            d2_max_index = i;
        }
    }

    if (d1_max > d2_max) {
        s[d1_max_index + d1_max] = '\0';
        s = &s[d1_max_index - d1_max + 1];

    }else {
        s[d2_max_index + d2_max] = '\0';
        s = &s[d2_max_index - d2_max];
    }

    return s;
}

int main(int argc, char *argv[]) {
    char s[] = "bb";
    printf("%s\n", longestPalindrome(s));
    return 0;
}