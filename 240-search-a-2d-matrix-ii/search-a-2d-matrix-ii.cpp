class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n=mat.size();
        int m=mat[0].size();
        int r=0;
        int c=m-1;
        while (c>=0 && r<n){
            if (target == mat[r][c]){
                return true;
            }
            else if (target < mat[r][c] ){
                c--;
            }
            else{
                r++;
            }

            
        }
        return false;
        
    }
};