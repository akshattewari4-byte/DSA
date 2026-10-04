class Solution {
public:
    bool checkValidString(string s) {

        stack<int> open;
        stack<int> star;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                open.push(i);
            }

            else if (s[i] == '*') {
                star.push(i);
            }

            else if (s[i] == ')') {

                // First try to match ')' with '('
                if (!open.empty()) {
                    open.pop();
                }

                // Otherwise use '*' as '('
                else if (!star.empty()) {
                    star.pop();
                }

                // Nothing available
                else {
                    return false;
                }
            }
        }

        // Remaining '(' can be matched with '*' 
        // but '*' must come AFTER '('
        while (!open.empty() && !star.empty()) {

            if (open.top() < star.top()) {
                open.pop();
                star.pop();
            }
            else {
                return false;
            }
        }

        // If '(' are still left, invalid
        return open.empty();
    }
};