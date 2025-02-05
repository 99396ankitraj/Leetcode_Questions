class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        int i = 0 , count = 0;
        int ind = -1;
        while(i < n){
            if(s1[i] != s2[i]){
                count++;
                if(count == 1){
                    ind = i;
                }else if(count == 2){
                    if(s1[ind] != s2[i] || s1[i] != s2[ind]) return false;
                }else{
                    return false;
                }
            }
            i++;
        }
        return count%2 == 0;
    }
};