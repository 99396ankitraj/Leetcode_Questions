class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int inc_count = 1 , dec_count = 1 , max_count = 1;
        for(int i = 1 ; i < n ; i++){
            nums[i-1] < nums[i] ? inc_count++ : inc_count = 1;
            nums[i-1] > nums[i] ? dec_count++ : dec_count = 1;
            max_count = max(max_count,max(inc_count,dec_count));
        }
        return max_count;
    }
};