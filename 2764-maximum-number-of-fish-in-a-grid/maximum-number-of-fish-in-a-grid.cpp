class Solution {
public:
    void solve(int i , int j , vector<vector<int>>& grid , vector<pair<int,int>>dir , int n , int m , int &sum){
            if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0){
                return ;
            }
            
            sum += grid[i][j];   
            grid[i][j] = 0;

            for(int ind = 0 ; ind < 4 ; ind++){
                int nexti = i + dir[ind].first;
                int nextj = j + dir[ind].second;
                solve(nexti , nextj , grid , dir , n , m , sum);
            }
            return;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<pair<int,int>>dir = {{1,0} , {0,-1} , {0,1} , {-1,0}};
        int maxi = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] != 0){
                    int sum = 0;
                    solve(i , j , grid , dir , n , m , sum);
                    maxi = max(maxi , sum);
                }
            }
        }
        return maxi;
    }
};