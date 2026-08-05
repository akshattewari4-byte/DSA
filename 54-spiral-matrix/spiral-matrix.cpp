class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> ans;

        int sr = 0;
        int sc = 0;

        int n = mat[0].size(); // columns
        int m = mat.size();    // rows

        int er = m - 1;
        int ec = n - 1;

        while (sr <= er && sc <= ec) {

            // Top row
            for (int j = sc; j <= ec; j++) {
                ans.push_back(mat[sr][j]);
            }

            // Right column
            for (int i = sr + 1; i <= er; i++) {
                ans.push_back(mat[i][ec]);
            }

            // Bottom row
            for (int j = ec - 1; j >= sc; j--) {
                if (sr == er) {
                    break;
                }
                ans.push_back(mat[er][j]);
            }

            // Left column
            for (int i = er - 1; i > sr; i--) {
                if (sc == ec) {
                    break;
                }
                ans.push_back(mat[i][sc]);
            }

            sr++;
            sc++;
            er--;
            ec--;
        }

        return ans;
    }
};