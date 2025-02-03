class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, pair<int,int>>> q;
        q.push({1,{0,0}});
        
        if(grid[0][0] == 1) return -1;

        if(grid[0].size() == 1 && grid.size() == 1) return 1;
       
        vector<pair<int,int>> dir = {{1,0} , {0,-1} , {0,1} , {-1,0} , {-1,-1} , {-1,1} , {1,-1} ,{1,1}};

        while(!q.empty()){
            auto top = q.front();
            int dis = top.first;
            int i = top.second.first;
            int j = top.second.second;
            q.pop();

            for(int ind = 0 ; ind < 8 ; ind++){
                int nexti = i + dir[ind].first;
                int nextj = j + dir[ind].second;
                if(nexti >= 0 && nexti < n && nextj >= 0 && nextj < n && grid[nexti][nextj] == 0){
                    if(nexti == n-1 && nextj == n-1) return dis+1;
                    grid[nexti][nextj] = 1;
                    q.push({dis+1,{nexti,nextj}});
                }
            }
        }
        return -1;
    }
};