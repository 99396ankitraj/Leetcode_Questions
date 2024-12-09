class Solution {
public:
    void solve(int ind , vector<int>&arr , vector<int>&nums , vector<vector<int>>&ans){
        ans.push_back(arr);

        for(int i = ind ; i < nums.size() ; i++){
            if(i != ind && nums[i] == nums[i-1]) continue;
            arr.push_back(nums[i]);
            solve(i+1 , arr , nums , ans);
            arr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> arr;

        solve(0 , arr , nums , ans);

        return ans;
    }
};