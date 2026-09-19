class Solution {
public:
    double myPow(double x, int n) {

        long long binaryform = n;

        if (binaryform < 0) {
            x = 1 / x;
            binaryform = -binaryform;
        }

        double ans = 1.0;

        while (binaryform > 0) {

            if (binaryform % 2 == 1) {
                ans *= x;
            }

            x *= x;
            binaryform /= 2;
        }

        return ans;
    }
};