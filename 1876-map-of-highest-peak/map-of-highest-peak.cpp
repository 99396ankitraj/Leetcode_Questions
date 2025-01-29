class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> ans(n , vector<int>(m , -1));
        queue<pair<int,int>> q;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(isWater[i][j] == 1){
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }

        vector<pair<int,int>> dir = {{1,0} , {0,-1} , {0,1} , {-1,0}};

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int ind = 0 ; ind < 4 ; ind++){
                int nexti = i + dir[ind].first;
                int nextj = j + dir[ind].second;
                if(nexti >= 0 && nexti < n && nextj >= 0 && nextj < m && ans[nexti][nextj] == -1){
                    q.push({nexti,nextj});
                    ans[nexti][nextj] = ans[i][j]+1;
                }
            }
        }

        return ans;
    }
};