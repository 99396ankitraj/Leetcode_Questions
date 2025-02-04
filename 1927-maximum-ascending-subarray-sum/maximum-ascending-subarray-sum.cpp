class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0] , maxi = nums[0];

        for(int i = 1 ; i < n ; i++){
            nums[i-1] < nums[i] ? sum += nums[i] : sum = nums[i];
            maxi = max(maxi , sum);
        }

        return maxi;
    }
};