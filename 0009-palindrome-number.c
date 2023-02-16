#include <stdio.h>
#define true 1;
#define false 0;
typedef short bool;

bool isPalindrome(int x){
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }
    if (x < 10) {
        return true;
    }

    int half_reversed = 0;

    while (x > half_reversed) {
        half_reversed = half_reversed * 10 + x % 10;
        x /= 10;
    }

    return x == half_reversed || x == half_reversed / 10;
}
