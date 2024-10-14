class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto it = nums.end() - k;
        nth_element(nums.begin(), it, nums.end());
        return *it;
    }
};