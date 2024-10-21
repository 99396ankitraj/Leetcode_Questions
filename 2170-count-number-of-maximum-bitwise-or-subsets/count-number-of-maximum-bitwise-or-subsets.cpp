class Solution {
public:
    int solve(int index , vector<int>&nums , int maxi , int ans){
        if(index < 0){
            if(maxi == ans) return 1;
            return 0;
        }

        int pick = solve(index-1 , nums , maxi , ans | nums[index]);
        int notPick = solve(index-1 , nums , maxi , ans);
        return pick + notPick;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0 , ans = 0;
        for(auto itr : nums) maxi |= itr;
        return solve( nums.size()-1 , nums , maxi , ans);
    }
};