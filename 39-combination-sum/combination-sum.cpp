class Solution {
public:
    void combineSum(vector<int>& arr, int i, vector<int>& combine,
                    vector<vector<int>>& ans, int target) {

        // Target achieved
        if (target == 0) {
            ans.push_back(combine);
            return;
        }

        // Invalid condition
        if (i >= arr.size() || target < 0) {
            return;
        }

        // Include current element
        combine.push_back(arr[i]);

        // i stays same -> can use same element again
        combineSum(arr, i, combine, ans, target - arr[i]);

        // Backtracking
        combine.pop_back();

        // Exclude current element
        combineSum(arr, i + 1, combine, ans, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;

        combineSum(candidates, 0, combine, ans, target);

        return ans;
    }
};