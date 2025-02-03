class Solution {
public:
    vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    typedef pair<int,pair<int,int>> p;
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();

        priority_queue<p,vector<p>,greater<p>> pq;
        vector<vector<int>> dist(n , vector<int>(m , INT_MAX));
        dist[0][0] = 0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();

            int d = node.first;
            int i = node.second.first;
            int j = node.second.second;

            if(i == n-1 && j == m-1){
                return dist[i][j];
            }

            if(d > dist[i][j])continue;

            for(auto dir : directions){
                int ni = i + dir[0];
                int nj = j + dir[1];

                if(ni >= 0 && ni < n && nj >= 0 && nj < m){
                    int dif = max(d, abs(h[ni][nj] - h[i][j]));
                    if(dist[ni][nj]  > dif){
                        dist[ni][nj] = dif;
                        pq.push({dif,{ni,nj}});
                    } 
                }
            }
        }
        return dist[n-1][m-1];
    }
};