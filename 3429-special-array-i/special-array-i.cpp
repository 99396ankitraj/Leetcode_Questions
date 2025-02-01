class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return true;
        //if(n == 2) return !((nums[0]+nums[1])%2 == 0);

        for(int i = 1 ; i < n ; i++){
            if((nums[i]+nums[i-1])%2 == 0) return false;
        }
        return true;
    }
};