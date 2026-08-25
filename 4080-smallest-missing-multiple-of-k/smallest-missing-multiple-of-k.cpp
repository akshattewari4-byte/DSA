class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        int i=1;
        while (true){
            int multiple=k*i;
            if (st.find(multiple) == st.end()) {
                return multiple;
            }
            i++;    
        }  
        return 0;          
    }
};