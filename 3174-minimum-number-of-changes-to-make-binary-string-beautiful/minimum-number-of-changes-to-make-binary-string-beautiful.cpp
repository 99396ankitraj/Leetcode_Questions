class Solution {
public:
    int minChanges(string s) {
        int ans = 0 , n = s.length();
        for(int k = 0 ; k < n ; k += 2){
            if(s[k] != s[k+1]) ans++;
        }
        
        return ans;
    }
};