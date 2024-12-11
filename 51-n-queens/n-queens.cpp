class Solution {
public:
    bool pathCheck(int row , int col , vector<string> &store , int n){
        //check for upper diognal
        int i = row;
        int j = col;
        while(i >= 0 && j >= 0){
            if(store[i][j] == 'Q') return false;
            i--;
            j--;
        }
        //check for left
        i = row;
        j = col;
        while(j >= 0){
            if(store[i][j] == 'Q') return false;
            j--;
        }
        //check for down diogonal
        i = row;
        j = col;
        while(i < n && j >= 0){
            if(store[i][j] == 'Q') return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int col , vector<string> &store , vector<vector<string>> &ans , int n){
        if(col == n){
            ans.push_back(store);
            return;
        }

        for(int row = 0 ; row < n ; row++){
            if(pathCheck(row , col , store , n)){
                store[row][col] = 'Q';
                solve(col+1 , store , ans , n);
                store[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n , '.');
        vector<string> store(n , s);
        
        solve(0 , store , ans , n);
        return ans;
    }
};