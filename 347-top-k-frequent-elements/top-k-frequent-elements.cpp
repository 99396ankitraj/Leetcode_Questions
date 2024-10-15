class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> pq;
        vector<int> ans;

        for (auto itr : nums)
            mp[itr]++;

        for (auto itr : mp)
            pq.push({itr.second, itr.first});

        while (k > 0) {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return ans;
    }
};