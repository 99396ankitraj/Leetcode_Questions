class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans = "";
        int n = s.length() , m = part.length();

        for(int i = 0 ; i < n ; i++){
            ans.push_back(s[i]);
            
            int si = ans.length()-m;
            if(si >= 0 && ans.substr(si , m) == part){
                cout<<ans<<endl;
                for(int i = 0 ; i < m ; i++){
                    ans.pop_back();
                }
            }
        }
        return ans;
    }
};