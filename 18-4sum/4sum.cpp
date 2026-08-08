class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {

            // skip duplicate i
            if (i > 0 && nums[i] == nums[i-1])
                continue;

            int j = i + 1;

            while (j < n - 2) {

                // skip duplicate j
                if (j > i + 1 && nums[j] == nums[j-1]) {
                    j++;
                    continue;
                }

                int p = j + 1;
                int q = n - 1;

                while (p < q) {

                    long long sum = (long long)nums[i] +
                                    nums[j] +
                                    nums[p] +
                                    nums[q];

                    if (sum < target) {
                        p++;
                    }
                    else if (sum > target) {
                        q--;
                    }
                    else {
                        ans.push_back({
                            nums[i],
                            nums[j],
                            nums[p],
                            nums[q]
                        });

                        p++;
                        q--;

                        // skip duplicate p
                        while (p < q && nums[p] == nums[p-1])
                            p++;

                        // skip duplicate q
                        while (p < q && nums[q] == nums[q+1])
                            q--;
                    }
                }

                j++;
            }
        }

        return ans;
    }
};