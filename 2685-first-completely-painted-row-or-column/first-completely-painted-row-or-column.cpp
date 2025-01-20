class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int,int>>mp;
        int n = mat.size() , m = mat[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                mp[mat[i][j]] = {i , j};
            }
        }
        vector<int>rows(n,m);
        vector<int>col(m,n);

        for(int i = 0 ; i < arr.size() ; i++){
            rows[mp[arr[i]].first]--;
            col[mp[arr[i]].second]--;
            if(!rows[mp[arr[i]].first] || !col[mp[arr[i]].second]) return i;

        }


        return 0;
    }
};