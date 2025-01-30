class Solution {
public:
    vector<pair<int,int>> dir = {{1,0} , {0,-1} , {0,1} , {-1,0}};
    void dfs(int i ,int j , vector<vector<int>>& grid , int n , int m , int &count){
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) return;

        count++;
        grid[i][j] = 0;

        for(auto itr : dir){
            int nexti = i + itr.first;
            int nextj = j + itr.second;
            dfs(nexti , nextj , grid , n , m , count);
        }
        //return ;
    }
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row(n , 0);
        vector<int> col(m , 0);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]){
                    int count = 0;
                    dfs(i , j , grid , n , m , count);
                    if(count > 1 || row[i] > 1 || col[j] > 1){
                        ans += count;
                    }
                }
            }
        }
        return ans;
    }
};