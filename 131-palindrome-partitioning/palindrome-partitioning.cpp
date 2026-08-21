class Solution {
public:

    bool ispal(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s == s2;
    }

    void getallpart(string s, vector<string>& partation,
                    vector<vector<string>>& ans) {

        // Base case
        if (s.size() == 0) {
            ans.push_back(partation);
            return;
        }

        // Try every possible prefix
        for (int i = 0; i < s.size(); i++) {

            string part = s.substr(0, i + 1);

            if (ispal(part)) {

                // Choose
                partation.push_back(part);

                // Explore
                getallpart(s.substr(i + 1), partation, ans);

                // Backtrack
                partation.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> partation;

        getallpart(s, partation, ans);

        return ans;
    }
};