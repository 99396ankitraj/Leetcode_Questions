class Solution {
public:
    void solve(int ind , int cc , int &maxi , string s , int n , unordered_set<string>&st){
        if(cc + (n-ind) < maxi) return;

        if(ind >= n){
            maxi = max(maxi , cc);
            return;
        }

        for(int j = ind ; j < n ; j++){
            string str = s.substr(ind , j-ind+1);
            if(st.find(str) == st.end()){
                st.insert(str);
                solve(j+1 , cc+1 , maxi , s , n , st);
                st.erase(str);
            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string>store;
        int maxcount = 0;
        solve(0 , 0 , maxcount , s , s.size() , store);

        return maxcount;
    }
};