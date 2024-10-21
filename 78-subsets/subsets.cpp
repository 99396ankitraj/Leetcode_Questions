class Solution {
public:
    void solve(vector<int>nums, vector<vector<int>>&ans,vector<int>v,int n ,int i){
        if(i == n){
            ans.push_back(v);
            return;
        }
        //  function for no peak element
        v.push_back(nums[i]);
        solve(nums,ans,v,n ,i+1);
        v.pop_back();
        //  function for peak the element
        solve(nums,ans,v,n ,i+1);
       

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        vector<int>v;
        solve(nums,ans,v,n,0);


        return ans;
    }
};