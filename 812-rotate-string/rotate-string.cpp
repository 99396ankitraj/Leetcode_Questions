class Solution {
public:
    string leftShift(string s){
        if(s.empty()) return s;
        char ch = s[0];
        return s.substr(1) + ch;
    }
    bool rotateString(string s, string goal) {
        int n = s.length();
        if(n != goal.length()) return false;
        for(int i = 0 ; i < n ; i++){
            if(s == goal) return true;
            s = leftShift(s);
        }
        return false;
    }
};