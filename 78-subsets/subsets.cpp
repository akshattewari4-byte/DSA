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
        getsubsets(nums, ans, i + 1, allsubsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> allsubsets;

        getsubsets(nums, ans, 0, allsubsets);

        return allsubsets;
    }
};