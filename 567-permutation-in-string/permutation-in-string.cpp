class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        int n = s1.length(), m = s2.length();
        unordered_map<char, int> s1_map, s2_map;
        for(char c : s1) s1_map[c]++;
        for(int i = 0; i < n; ++i) s2_map[s2[i]]++;
        for(int i = 0; i <= m - n; ++i) {
            if(i > 0) {
                s2_map[s2[i - 1]]--;
                if(s2_map[s2[i - 1]] == 0) s2_map.erase(s2[i - 1]);
                s2_map[s2[i + n - 1]]++;
            }
            if(s1_map == s2_map) return true;
        }
        return false;
    }
};
