class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }
        if(fresh==0) return 0;

        int dr[4] = {-1,0,0,1};
        int dc[4] = {0,1,-1,0};

        int time = 0;
        while(!q.empty()){
            int size = q.size();
            int timerUpdate = 0;

            for(int i=0;i<size;i++){
                int r = q.front().first;
                int c = q.front().second;

                q.pop();
                
                for(int i=0;i<4;i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                        q.push({nr,nc});
                        grid[nr][nc] = 2;
                        fresh--;
                        timerUpdate = 1;
                    }
                }
            }
             if(timerUpdate) time++;
        }
        return  (fresh == 0) ? time : -1;
    }
};