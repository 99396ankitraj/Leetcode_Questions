class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length(), i = 0, j = 1;
        string ans = "";
        if (n < 3) return s;
        while (j < n) {
            if (s[i] == s[j]) {
                while (s[i] == s[j]) j++;
                    ans += s[i];
                    ans += s[i];
                    i = j;
                    j++;
            } else {
                ans += s[i];
                i++;
                j++;
            }
        }
        if(s[n-2] != s[n-1]) ans += s[n-1];
        return ans;
    }
};
static const auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();