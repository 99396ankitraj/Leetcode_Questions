class Solution {
public:
    bool checkpath(int row , int col , vector<string> &chess , int n){
        //check for upper diogonal
        int i = row;
        int j = col;
        while(i >= 0 && j >= 0){
            if(chess[i][j] == 'Q') return false;
            i--; j--;
        }

        //left check
        i = row;
        j = col;
        while(j >= 0){
            if(chess[i][j] == 'Q') return false;
            j--;
        }

        //check for down diogonal
        i = row;
        j = col;
        while(i < n &&j >= 0){
            if(chess[i][j] == 'Q') return false;
            i++; j--;
        }
         
         return true;
    }
    int solve(int col , int n , vector<string>&chess ,int &count){
        if(col == n) count++;
        
        for(int row = 0 ; row < n ; row++){
            if(checkpath(row , col , chess , n)){
                chess[row][col] = 'Q';
                solve(col+1 , n , chess ,count);
                chess[row][col] = '.';
            }
        }
        return 0;
    }
    int totalNQueens(int n) {
        string  s(n , '.');
        vector<string> chess(n , s);
        int count = 0;

        solve(0 , n , chess , count);
        return count;
    }
};