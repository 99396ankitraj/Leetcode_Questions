class Solution {
public:
    int dfs(int i , int j , vector<vector<int>>& grid ,  vector<pair<int,int>>dir ,int m , int n){
        int fish = grid[i][j];
        grid[i][j] = 0;

        for(int ind = 0 ; ind < 4 ; ind++){
            int nexti = i + dir[ind].first;
            int nextj = j + dir[ind].second;
            if(nexti >= 0 && nexti < n && nextj >= 0 && nextj < m && grid[nexti][nextj] != 0){
                fish += dfs(nexti , nextj , grid , dir , m , n);
            }
        }
        return fish;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>>dir = {{1,0} ,{0,-1} ,{0,1} ,{-1,0}};
        int maxi = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] != 0){
                    maxi = max(maxi ,dfs(i , j , grid , dir , m , n));
                }
            }
        }
        return maxi;
    }
};