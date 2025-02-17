class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            int count = 2*k-1;
            int flag = 0;
            for(int j = i+1 ; j < n ; j++){
                if(nums[j-1] < nums[j]){
                    count--;
                }else{
                    if(count-k != 0) break;
                    count--;
                }
                if(count == 0) return true;
            }
        }
        return false;
    }
};