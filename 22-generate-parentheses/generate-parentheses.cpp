class Solution {
public:
    void solve(int open , int close , int n , vector<string>&ans , string str){
         if(str.length() == 2*n){
            ans.push_back(str);
            return;
         }

         if(open < n){
            solve(open+1 , close , n , ans , str+'(');
         }

         if(close < open){
            solve(open , close+1 , n , ans , str+')');
         }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str = "";
        solve(0 , 0 , n , ans , str);

        return ans;
    }
};