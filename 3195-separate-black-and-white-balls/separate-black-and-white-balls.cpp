class Solution {
public:
    long long minimumSteps(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        long long res=0,cur=0;
        for(int i=0;i<s.length();++i){
            if(s[i]=='0'){res+=i-cur;++cur;}
        }

        return res;
    }
};