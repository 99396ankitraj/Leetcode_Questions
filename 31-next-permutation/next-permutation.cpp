class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-1;
        while(i > 0){
            if(nums[i-1] < nums[i]){
                int j = nums.size()-1;
                while(nums[i-1] >= nums[j]){
                    j--;
                }
                swap(nums[j] , nums[i-1]);
                reverse(nums.begin()+i , nums.end());
                return;
            }
            i--;
        }
        reverse(nums.begin(), nums.end());
        return;
    }
};