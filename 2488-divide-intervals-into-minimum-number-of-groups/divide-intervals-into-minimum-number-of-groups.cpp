class Solution {
public:
    int minGroups(vector<vector<int>>& times) {
        sort(times.begin(), times.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        priority_queue<int , vector<int> , greater<int>> st;
        int chair = 0;

        for (auto itr : times) {
            int arival = itr[0];
            int departure = itr[1];

            while (!pq.empty() && arival > pq.top().first) {
                st.push(pq.top().second);
                pq.pop();
            }
            if (!st.empty()) {
                pq.push({departure, st.top()});
                st.pop();
            } else {
                pq.push({departure, chair++});
            }
        }
        return chair;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();