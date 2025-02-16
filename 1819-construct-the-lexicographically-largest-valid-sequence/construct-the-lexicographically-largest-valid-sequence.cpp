class Solution {
public:
    bool solve(int ind , int n , vector<int>& ans , int m , vector<bool>&vis){
        if(ind == m) return true;

        if(ans[ind] != -1) return solve(ind+1 , n  ,ans, m , vis);

        for(int i = n ; i >= 1 ; i--){
            if(vis[i]) continue;
            if(i == 1){
                ans[ind] = i;
                vis[i] = true;
                if(solve(ind+1 , n , ans , m , vis)) return true;
                ans[ind] = -1;
                vis[i] = false;
                }
            if(ans[ind] == -1){
                if(i+ind < m && ans[i+ind] == -1){
                   vis[i] = true;
                   ans[ind] = i;
                   ans[i+ind] = i;
                   if(solve(ind+1 , n , ans , m , vis)) return true;
                   vis[i] = false;
                   ans[ind] = -1;
                   ans[i+ind] = -1;
                }
            }
        }
        return false;

    }
    vector<int> constructDistancedSequence(int n) {
        int m = 2*n-1;
        vector<int> ans(m , -1);
        vector<bool> vis(n+1 , false);
        solve(0 , n , ans , m , vis);
        return ans;
    }
};