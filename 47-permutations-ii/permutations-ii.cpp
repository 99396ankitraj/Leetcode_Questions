class Solution {
public:
    void solve(int ind , vector<int>nums , vector<vector<int>>&result , int n){
        if(ind == n){
            result.push_back(nums);
            return ;
        }

        for(int i = ind ; i < n ; i++){
            if(i != ind && nums[i] == nums[ind]) continue;
            swap(nums[i] ,nums[ind]);
            solve(ind+1 , nums , result , n);
            //swap(nums[i] ,nums[ind]);
        }
        return ;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> result;

        solve(0 , nums , result , n);
        return result;
    }
};