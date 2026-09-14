class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;       // indices store karenge
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {

            // 1. Window se bahar wale index remove karo
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // 2. Chhote elements remove karo
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // 3. Current index add karo
            dq.push_back(i);

            // 4. Jab first window complete ho jaye
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};