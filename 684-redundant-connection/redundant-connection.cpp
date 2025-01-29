class Solution {
public:
    int findParent(vector<int>&parent , int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent , parent[node]); 
    }
    void unionSet( vector<int>&parent ,  vector<int>&rank , int u , int v){
        if(rank[u] > rank[v]) parent[v] = u;
        else if(rank[u] < rank[v]) parent[u] = v;
        else{
            rank[u]++;
            parent[v] = u;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>parents(n+1);
        vector<int>rank(n+1,0);

        for(int i = 0 ; i <= n ; i++) parents[i] = i;

        for(auto itr : edges){
            int u = findParent(parents , itr[0]);
            int v = findParent(parents , itr[1]);
            if(u != v){
                unionSet(parents , rank , u , v);
                //cout<<"ankit"<<endl;
            }
            else return {itr[0] ,itr[1]};
        }

        return {};
    }
};