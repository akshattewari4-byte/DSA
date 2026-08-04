class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> ans(col, vector<int>(rows));

        for (int j = 0; j < col; j++) {
            for (int i = 0; i < rows; i++) {
                ans[j][i] = matrix[i][j];
            }
        }

        return ans;
    }
};