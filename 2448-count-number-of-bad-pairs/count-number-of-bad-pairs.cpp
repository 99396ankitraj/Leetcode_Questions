class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        long long goodPairs = 0;
        
        // Loop through the array and calculate the frequency of each `nums[i] - i` value
        for (int i = 0; i < n; ++i) {
            int diff = nums[i] - i;  // Calculate the difference
            goodPairs += mp[diff];    // Count how many times this difference has occurred before
            mp[diff]++;               // Increment the frequency of this difference
        }
        
        // Total number of pairs in the array (i, j) with i < j
        long long totalPairs = (long long)n * (n - 1) / 2;
        
        // Bad pairs are the total pairs minus the good pairs
        return totalPairs - goodPairs;
    }
};
