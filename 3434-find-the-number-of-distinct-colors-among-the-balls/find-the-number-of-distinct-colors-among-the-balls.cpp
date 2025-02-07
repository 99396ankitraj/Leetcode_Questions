class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        unordered_map<int,int> mp;
        unordered_map<int,int> colormp;
        vector<int>ans(n);

        for(int i = 0 ; i < n ; i++){
           int ball = queries[i][0];
           int color = queries[i][1];

           if(mp.count(ball)){
             int prev = mp[ball];
             colormp[prev]--;

             if(colormp[prev] == 0){
                colormp.erase(prev);
             }
           }
           mp[ball] = color;
           colormp[color]++;

           ans[i] = colormp.size();
         
        }
        return ans;
    }
};