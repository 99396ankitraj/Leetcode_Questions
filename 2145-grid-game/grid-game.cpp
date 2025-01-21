class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long rowsum = 0;
        long long bottomsum = 0;
        for(int i = 0 ; i < grid[0].size() ; i++){
            rowsum += grid[0][i];
        } 
        cout<<rowsum;
        long long ans = LLONG_MAX;
        for(int i = 0 ; i < grid[0].size() ; i++){
            rowsum -= grid[0][i];
            long long robot2 = max(rowsum , bottomsum);
            bottomsum += grid[1][i];

            ans = min(robot2 , ans);
        }
        return ans;
    }
};