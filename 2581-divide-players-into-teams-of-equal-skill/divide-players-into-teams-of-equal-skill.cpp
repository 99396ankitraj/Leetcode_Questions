#define ll long long
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        ll totalSum = accumulate(skill.begin(), skill.end(), 0ll);
        if (totalSum % (skill.size() / 2) != 0) return -1;
        int target = totalSum / (skill.size() / 2);

        unordered_map<int, int> mp;
        vector<pair<int, int>> pairs;

        for (auto& s : skill) {
            mp[s]++;
        }

        for(auto itr : mp) cout<<itr.first<<" "<<itr.second<<endl;

        for (auto& s : skill) {
            if (mp[s] == 0) continue;

            int complement = target - s;
            if (mp[complement] == 0) return -1;

            pairs.push_back({s, complement});
            mp[s]--;
            mp[complement]--;
        }

        ll ans = 0;
        for (auto& p : pairs) {
            ans += p.first * p.second;
        }

        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();