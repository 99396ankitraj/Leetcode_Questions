class Solution {
public:
    bool solve(int node , vector<int> &vis , vector<vector<int>>& adj){
        queue<int>q;
        q.push(node);
        vis[node] = 0;

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            for(auto itr : adj[top]){
                if(vis[itr] == -1 ){
                    q.push(itr);
                    vis[itr] = !(vis[top]);
                }else if(vis[itr] == vis[top]){
                    return false;
                }
            }
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n , -1);

        for(int i = 0 ; i < n ; i++){
            if(vis[i] == -1){
                if(!solve(i , vis , graph)){
                    return false;
                }
            }
        }
        return true;
    }
};