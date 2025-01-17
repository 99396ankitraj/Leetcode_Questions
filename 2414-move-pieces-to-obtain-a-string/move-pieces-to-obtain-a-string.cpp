class Solution {
public:
    bool canChange(string s, string t) {
        int i=0,j=0;
        while(i<s.size() && j<t.size()){
           while(s[i] == '_') i++;
           while(t[j] == '_') j++;

           if(s[i] == t[j]){
            if((s[i] == 'L' and i<j) or (s[i] == 'R' and i>j)) return false;
           }
           else return false;
           i++;j++;
        }
        while(i<s.length() && s[i] == '_') i++;
        while(j<t.length() && t[j] == '_') j++;

        return i==j;
    }
};