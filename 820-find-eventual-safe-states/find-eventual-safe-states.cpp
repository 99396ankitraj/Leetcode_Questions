class Solution {
public:
    bool solve(int node , vector<bool> &vis , vector<bool> &dfs , vector<vector<int>>& adj){
        vis[node] = true;
        dfs[node] = true;

        for(auto itr : adj[node]){
            if(!vis[itr]){
                if(solve(itr , vis , dfs , adj)) return true;
            }else if(dfs[itr]){
                return true;
            }
        }
        dfs[node] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();
        vector<bool> vis(n , 0);
        vector<bool> dfs(n , 0);

        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                solve(i , vis , dfs , graph);
            }
        }

        vector<int>ans;
        for(int i = 0 ; i < n ; i++){
            if(!dfs[i]) ans.push_back(i);
        }

        return ans;
    }
};