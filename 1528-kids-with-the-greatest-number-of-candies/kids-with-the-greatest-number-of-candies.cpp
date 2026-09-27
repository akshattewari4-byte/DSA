class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int greatest = candies[0];
        vector<bool> ans(candies.size());

        // Greatest number of candies find karo
        for (int i = 1; i < candies.size(); i++) {
            if (candies[i] > greatest) {
                greatest = candies[i];
            }
        }

        // Har child check karo
        for (int i = 0; i < candies.size(); i++) {
            int x = candies[i] + extraCandies;

            if (x >= greatest) {
                ans[i] = true;
            } 
            else {
                ans[i] = false;
            }
        }

        return ans;
    }
};