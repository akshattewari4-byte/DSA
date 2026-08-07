class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {

        sort(a.begin(), a.end());

        int n = a.size();
        int target = 0;

        vector<vector<int>> ans;

        for (int fix = 0; fix < n - 2; fix++) {

            // duplicate fix skip
            if (fix > 0 && a[fix] == a[fix - 1])
                continue;

            int l = fix + 1;
            int r = n - 1;

            while (l < r) {

                int sum = a[fix] + a[l] + a[r];

                if (sum == target) {

                    ans.push_back({a[fix], a[l], a[r]});

                    l++;
                    r--;

                    // duplicate l skip
                    while (l < r && a[l] == a[l - 1])
                        l++;

                    // duplicate r skip
                    while (l < r && a[r] == a[r + 1])
                        r--;
                }
                else if (sum < target) {
                    l++;
                }
                else {
                    r--;
                }
            }
        }

        return ans;
    }
};