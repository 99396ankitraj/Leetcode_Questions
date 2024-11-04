class Solution {
public:
    string compressedString(string words) {
        int n = words.length();
        string ans = "";
        int i = 0;

        while (i < n) {
            int count = 1;
            while (i + 1 < n && words[i] == words[i + 1]) {
                i++;
                count++;
                if (count % 9 == 0) {
                    ans += '9';
                    ans += words[i];
                    count = 0;
                }
            }
            if (count > 0) {
                ans += (count + '0');
                ans += words[i];
            }
            i++;
        }

        return ans;
    }
};
