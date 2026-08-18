class Solution {
public:
    void getsubsets(vector<int>& nums, vector<int>& ans, int i,
                    vector<vector<int>>& allsubsets) {

        if (i == nums.size()) {
            allsubsets.push_back(ans);
            return;
        }

        // Include
        ans.push_back(nums[i]);
        getsubsets(nums, ans, i + 1, allsubsets);

        // Backtracking
        ans.pop_back();

        // Exclude
        int idx = i + 1;

        while (idx < nums.size() && nums[idx] == nums[idx-1]) {
            idx++;
        }

        getsubsets(nums, ans, idx, allsubsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> allsubsets;

        sort(nums.begin(), nums.end());

        getsubsets(nums, ans, 0, allsubsets);

        return allsubsets;
    }
};