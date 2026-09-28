/*
class Solution {
public:
    int maxDiff(int num) {
        
    }
};
*/

class Solution {
public:
    int maxDiff(int num) {

        string s = to_string(num);

        // Maximum number
        string maxi = s;

        for (int i = 0; i < maxi.size(); i++) {
            if (maxi[i] != '9') {
                char x = maxi[i];

                for (int j = 0; j < maxi.size(); j++) {
                    if (maxi[j] == x) {
                        maxi[j] = '9';
                    }
                }

                break;
            }
        }

        // Minimum number
        string mini = s;

        if (mini[0] != '1') {

            char x = mini[0];

            for (int i = 0; i < mini.size(); i++) {
                if (mini[i] == x) {
                    mini[i] = '1';
                }
            }

        } else {

            for (int i = 1; i < mini.size(); i++) {
                if (mini[i] != '0' && mini[i] != '1') {

                    char x = mini[i];

                    for (int j = 1; j < mini.size(); j++) {
                        if (mini[j] == x) {
                            mini[j] = '0';
                        }
                    }

                    break;
                }
            }
        }

        return stoi(maxi) - stoi(mini);
    }
};