class Solution {
public:
    void per(vector<int>& nums, int idx, vector<vector<int>>& ans) {

        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {

            swap(nums[idx], nums[i]);

            per(nums, idx + 1, ans);

            swap(nums[idx], nums[i]);  // backtracking
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;

        per(nums, 0, ans);

        return ans;
    }
};