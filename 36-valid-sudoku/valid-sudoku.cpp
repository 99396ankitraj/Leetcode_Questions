class Solution {
public:
    bool validCheck(int row , int col , vector<vector<char>>& board ,char target){
        for(int i = 0 ; i < 9 ; i++){
            if(board[row][i] == target && i != col) return false;
            if(board[i][col] == target && i != row) return false;
            int j = 3*(row/3)+(i/3) , k = 3*(col/3)+(i%3);
            if(j == row && k == col) continue;
            if(board[j][k] == target ) return false;  

        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] != '.'){
                    if(!validCheck(i , j , board , board[i][j])){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};