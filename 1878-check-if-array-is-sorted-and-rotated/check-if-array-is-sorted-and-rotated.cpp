class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN, ind = -1;
        int i = 0;

        // Find the index where the order breaks
        while (i < n) {
            if (maxi < nums[i]) {
                maxi = nums[i];
                ind = i;
            }
            // If we detect a "break" (where nums[i] > nums[(i + 1) % n]), it's a potential rotation
            if (nums[i] > nums[(i + 1) % n]) {
                ind = i;
                break;
            }
            i++;
        }

        // Now check if the array is sorted in non-decreasing order after the "rotation"
        int m = ind + n;
        for (int i = ind + 1; i < m; i++) {
            if (nums[i % n] > nums[(i + 1) % n]) {
                return false;
            }
        }

        return true;
    }
};
