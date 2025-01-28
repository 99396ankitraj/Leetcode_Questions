class Solution {
public:
    bool solve(int i , int j , vector<vector<char>>& board , string word , vector<pair<int,int>> &dir , int k ,int n , int m){
        if(k == word.length()){
            return true;
        }

        for(int ind = 0 ; ind < 4 ; ind++){
            int nexti = i + dir[ind].first;
            int nextj = j + dir[ind].second;

            if(nexti >= 0  && nexti < n && nextj >= 0 && nextj < m && board[nexti][nextj] == word[k]){
                char temp = board[nexti][nextj];
                board[nexti][nextj] = '#';
                if(solve(nexti , nextj , board , word , dir , k+1 , n , m)) return true;
                board[nexti][nextj] = temp;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<pair<int,int>> dir = {{1,0},{0,-1},{0,1},{-1,0}};

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(word[0] == board[i][j]){
                    char temp = board[i][j];
                    board[i][j] = '#';
                    if(solve(i , j , board , word, dir , 1 , n , m)) return true;
                    board[i][j] = temp;
                }
            }
        }
        return false;
    }
};