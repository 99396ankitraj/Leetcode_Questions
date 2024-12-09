class Solution {
public:
    void solve(vector<vector<int>> &ans , vector<int>&arr , int target , vector<int>& can , int i){
        if(i == can.size()){
            if(target == 0){
                ans.push_back(arr);
            }
            return;
        }
        //condition for pick element
        if(target >= can[i]){
            arr.push_back(can[i]);
            solve(ans , arr , target-can[i] , can , i);
            arr.pop_back();
        }
        //condition for not pick
        solve(ans , arr , target , can , i+1);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        vector<vector<int>> ans;
        vector<int>arr;
        solve(ans , arr , target , can , 0);
        return ans;
    }
};