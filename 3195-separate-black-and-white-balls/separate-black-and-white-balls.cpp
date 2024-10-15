class Solution {
public:
    long long minimumSteps(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        long long n = s.length() , ans = 0;
        int i = 0 , j = s.length()-1;

        while(i < j ){
            if(s[i] != '0' && s[j] != '1'){
                ans += (j-i);
                swap(s[i++] , s[j--]);
                
            }
            if(s[i] == '0') i++;
            if(s[j] == '1') j--;
        }
        
        return ans;
    }
};