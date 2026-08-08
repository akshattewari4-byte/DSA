/*
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
    }
};\

*/


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans;

        int i = 0, j = 0;

        // Merge both sorted arrays
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            }
            else {
                ans.push_back(nums2[j]);
                j++;
            }
        }

        // Remaining elements of nums1
        while (i < nums1.size()) {
            ans.push_back(nums1[i]);
            i++;
        }

        // Remaining elements of nums2
        while (j < nums2.size()) {
            ans.push_back(nums2[j]);
            j++;
        }

        int n = ans.size();

        // Odd
        if (n % 2 != 0) {
            return ans[n / 2];
        }

        // Even
        return (ans[n / 2 - 1] + ans[n / 2]) / 2.0;
    }
};