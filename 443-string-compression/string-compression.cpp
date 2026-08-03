class Solution {
public:
    int compress(vector<char>& chars) {

        int n = chars.size();
        int index = 0;     
        int count = 1;

        for (int i = 0; i < n; i++) {

            if (i + 1 < n && chars[i] == chars[i + 1]) {
                count++;
            }
            else {

                
                chars[index] = chars[i];
                index++;

                if (count > 1) {

                    string s = to_string(count);

                    for (char c : s) {
                        chars[index] = c;
                        index++;
                    }
                }

                count = 1;
            }
        }

        return index;

    }
};