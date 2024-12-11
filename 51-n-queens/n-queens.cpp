class Solution {
public:
    void solve(int col , vector<string> &store , vector<vector<string>> &ans , int n , vector<int> &leftRow , vector<int> &upperDiogonal , vector<int> &lowerDiogonal){
        if(col == n){
            ans.push_back(store);
            return;
        }

        for(int row = 0 ; row < n ; row++){
            if(leftRow[row] == 0 && lowerDiogonal[row+col] == 0 && upperDiogonal[n-1+col-row] == 0){
                store[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiogonal[row+col] = 1;
                upperDiogonal[n-1+col-row] = 1;

                solve(col+1 , store , ans , n , leftRow ,upperDiogonal ,lowerDiogonal);

                store[row][col] = '.';
                leftRow[row] = 0;
                lowerDiogonal[row+col] = 0;
                upperDiogonal[n-1+col-row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n , '.');
        vector<string> store(n , s);
        vector<int> leftRow(n , 0) , upperDiogonal(2*n-1 ,0) , lowerDiogonal(2*n-1 , 0);
        
        solve(0 , store , ans , n , leftRow , upperDiogonal , lowerDiogonal);
        return ans;
    }
};