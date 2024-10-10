class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int open = 0, ins = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                open++;
            else {
                if (i + 1 < n && s[i + 1] == ')') {
                    if (open > 0)
                        open--;
                    else
                        ins++;
                    i++;
                } else {
                    if (open > 0) {
                        ins++;
                        open--;
                    } else {
                       ins+=2;
                    }
                }
            }
        }
        return open * 2 + ins;
    }
};