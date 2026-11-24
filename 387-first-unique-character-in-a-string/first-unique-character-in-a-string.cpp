class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        queue<int> q;

        int n = s.size();

        for (int i = 0; i < n; i++) {

            m[s[i]]++;
            q.push(i);

            while (!q.empty() && m[s[q.front()]] > 1) {
                q.pop();
            }
        }

        if (q.empty()) {
            return -1;
        }

        return q.front();
    }
};