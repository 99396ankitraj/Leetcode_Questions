class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        int currentEnd = pairs[0][1], ans = 1;

        for (int i = 1; i < pairs.size(); i++) {
            if (currentEnd < pairs[i][0]) {
                ans++;
                currentEnd = pairs[i][1];
            }
        }

        return ans;
    }
};