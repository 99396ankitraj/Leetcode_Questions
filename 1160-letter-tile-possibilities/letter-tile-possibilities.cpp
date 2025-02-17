class Solution {
public:
    void solve(vector<bool> &vis,unordered_set<string> &st , string str , string&tiles){
        st.insert(str);

        for(int i = 0 ; i < tiles.length() ; i++){
            if(!vis[i]){
                vis[i] = true;
                str.push_back(tiles[i]);
                solve(vis , st , str , tiles);
                vis[i] = false;
                str.pop_back();
            }
        }

    }
    int numTilePossibilities(string tiles) {
        vector<bool>vis(tiles.size() , false);
        unordered_set<string> st;
        solve(vis , st , "" , tiles);
        return st.size()-1;
    }
};