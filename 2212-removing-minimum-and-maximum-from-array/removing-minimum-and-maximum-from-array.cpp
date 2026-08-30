class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int n = nums.size();

        int minIndex = 0;
        int maxIndex = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }

            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }

        // Ensure minIndex comes before maxIndex
        if (minIndex > maxIndex) {
            swap(minIndex, maxIndex);
        }

        // Case 1: Remove both from front
        int front = maxIndex + 1;

        // Case 2: Remove both from back
        int back = n - minIndex;

        // Case 3: Remove one from front and one from back
        int both = (minIndex + 1) + (n - maxIndex);

        return min({front, back, both});
    }
};