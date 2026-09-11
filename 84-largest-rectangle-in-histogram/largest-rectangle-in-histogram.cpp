class Solution {
public:
    int largestRectangleArea(vector<int>& height) {

        int n = height.size();

        // Right Smaller Element
        stack<int> s;
        vector<int> right(n);

        for (int i = n - 1; i >= 0; i--) {

            while (!s.empty() && height[s.top()] >= height[i]) {
                s.pop();
            }

            right[i] = s.empty() ? n : s.top();

            s.push(i);
        }

        // Left Smaller Element
        while (!s.empty()) {
            s.pop();
        }

        vector<int> left(n);

        for (int i = 0; i < n; i++) {

            while (!s.empty() && height[s.top()] >= height[i]) {
                s.pop();
            }

            left[i] = s.empty() ? -1 : s.top();

            s.push(i);
        }

        // Calculate maximum area
        int ans = 0;

        for (int i = 0; i < n; i++) {

            int width = right[i] - left[i] - 1;

            int currentArea = height[i] * width;

            ans = max(ans, currentArea);
        }

        return ans;
    }
};