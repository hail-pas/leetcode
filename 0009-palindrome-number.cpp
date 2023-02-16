class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 or (x % 10 == 0 and x != 0)) {
            return false;
        }
        if (x < 10) return true;

        int half_reversed = 0;

        while (x > half_reversed) {
            half_reversed = half_reversed * 10 + x % 10;
            x /= 10;
        }

        return x == half_reversed or half_reversed / 10 == x;
    }
};
