class Solution {
public:
    int reverse(int x) {
        int revn = 0;

        while (x != 0) {
            int digit = x % 10;

            if (revn > INT_MAX / 10 || revn < INT_MIN / 10) {
                return 0;
            }

            revn = revn * 10 + digit;
            x = x / 10;
        }

        return revn;
    }
};