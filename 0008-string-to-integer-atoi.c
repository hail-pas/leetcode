#include <stdio.h>
#include <limits.h>

int myAtoi(char * s){
    long result = 0;
    short started = 0;
    short flag = 1;
    char temp;
    while (*s != '\0') {
        temp = *s;
        s++;
        if (started == 0) {
            if ('+' == temp) {
                started = 1;
                continue;
            }else if ('-' == temp) {
                started = 1;
                flag = -1;
                continue;
            }else if (' ' == temp) {
                continue;
            }
            else if (temp < '0' || '9' < temp) {
                break;
            }
        }
        if (temp <= '9' && temp >= '0') {
            started = 1;
            result = result * 10 + (temp - '0');
            if (flag * result <= INT_MIN) {
                return INT_MIN;
            }else if (flag * result >= INT_MAX) {
                return INT_MAX;
            }
        } else if (started == 1) break;
    }
    result = flag * result;
    return result;
}

int main(int argc, char *argv[]) {
    printf("%d", myAtoi("20000000000000000000"));
    return 0;
}
