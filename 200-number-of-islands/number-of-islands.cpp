class Solution {
public:
    vector<pair<int,int>> dir = {{1,0} , {0,-1} , {0,1} , {-1,0}};
    void dfs(int i , int j , vector<vector<char>>& grid , int n , int m){
         if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != '1') return;

         grid[i][j] = '0';

         for(auto itr : dir){
            int nexti = i + itr.first;
            int nextj = j + itr.second;
            dfs(nexti , nextj , grid , n , m);
         }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(i , j , grid , n , m);
                }
            }
        }
        return count;
    }
};