class Solution {
public:
    void solve(int ind , vector<vector<int>> &ans , vector<int>& nums , vector<int>&store , unordered_map<int ,int> &mp){
        if(store.size() == nums.size()){
            ans.push_back(store);
            return;
        }

        for(int i = 0 ; i < nums.size() ; i++){
            if(!mp[nums[i]]){
                mp[nums[i]] = true;
                store.push_back(nums[i]);
                solve(ind , ans , nums , store , mp);
                store.pop_back();
                mp[nums[i]] = false;
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>store;
        unordered_map<int ,int> mp;

        solve(0 , ans , nums , store , mp);

        return ans;
    }
};