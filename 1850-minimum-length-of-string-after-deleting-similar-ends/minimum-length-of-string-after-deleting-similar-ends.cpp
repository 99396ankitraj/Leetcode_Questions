class Solution {
public:
    int minimumLength(string s) {
        int i = 0 , j = s.length()-1;
        int ans = s.length();
        while(i < j){
            if(s[i] != s[j]){
                break;
            }else{
                while(i < j && s[i] == s[i+1]){
                    i++;
                }
                while(i < j && s[j] == s[j-1]){
                    j--;
                }
               i++;
               j--;
            }
        }
        
        return j-i >= 0 ? j - i + 1 : 0;
    }
};