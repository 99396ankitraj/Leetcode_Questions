class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            ans ^= nums[i];
            ans ^=(i+1);
        }
        return ans;
    }
};