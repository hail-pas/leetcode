
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int reverse(int x){
    long result = 0;
    short temp = 0;

    while (x != 0) {
        if (result < INT_MIN / 10 || result > INT_MAX / 10) {
            return 0;
        }
        temp = x % 10;
        x = x / 10;
        result = result * 10 + temp;
    }
    return result;
}

int main(int argc, char *argv[]) {
    int num = 123;
    printf("%d\n", reverse(num));
    return 0;
}
