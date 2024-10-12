class Solution {
public:
    int minGroups(vector<vector<int>>& times) {
        sort(times.begin(), times.end());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        set<int> st;
        int chair = 0;

        for (auto itr : times) {
            int arival = itr[0];
            int departure = itr[1];

            while (!pq.empty() && arival > pq.top()[0]) {
                st.insert(pq.top()[1]);
                pq.pop();
            }
            if (!st.empty()) {
                pq.push({departure, *st.begin()});
                st.erase(st.begin());
            } else {
                pq.push({departure, chair++});
            }
        }
        return chair;
    }
};