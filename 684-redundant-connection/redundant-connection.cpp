class Solution {
public:
    int findParent(vector<int>& parent, int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent, parent[node]); // Path compression
    }
    
    void unionSet(vector<int>& parent, vector<int>& rank, int u, int v) {
        if (rank[u] > rank[v]) parent[v] = u;
        else if (rank[u] < rank[v]) parent[u] = v;
        else {
            rank[u]++;
            parent[v] = u;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parents(n + 1);
        vector<int> rank(n + 1, 0);

        for (int i = 0; i <= n; i++) parents[i] = i;

        for (auto& edge : edges) {
            int u = findParent(parents, edge[0]);
            int v = findParent(parents, edge[1]);
            if (u != v) {
                unionSet(parents, rank, u, v);
            } else {
                return {edge[0], edge[1]};
            }
        }

        return {};
    }
};
