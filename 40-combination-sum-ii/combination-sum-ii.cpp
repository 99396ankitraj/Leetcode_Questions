class Solution {
public:
    void solve(vector<vector<int>> &ans , vector<int>&arr , vector<int>& can , int target , int ind){
        if(target == 0){
            ans.push_back(arr);
            return;
        }
        for(int i =  ind ; i < can.size() ; i++){
            if(i > ind && can[i] == can[i-1]) continue;
            if(target < can[i]) break;
                arr.push_back(can[i]);
                solve(ans , arr , can , target-can[i] , i + 1);
                arr.pop_back();
            
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        sort(can.begin() , can.end());
        vector<vector<int>> ans;
        vector<int>arr;

        solve(ans , arr , can , target , 0);

        return ans;
    }
};