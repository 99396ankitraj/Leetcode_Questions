class Solution {
public:
    bool isCircularSentence(string sen) {
        int n = sen.length() ;
        for(int i = 0 ; i < n ; i++){
            if(!isalpha(sen[i])){
                if(sen[i-1] != sen[i+1]) return false;
            }
        }
        if(sen.front() != sen.back()) return false;
        
        return true;
    }
};