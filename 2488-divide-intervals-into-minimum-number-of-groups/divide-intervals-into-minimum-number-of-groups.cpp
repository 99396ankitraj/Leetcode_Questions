class Solution {
public:
    int minGroups(vector<vector<int>>& times) {
        sort(times.begin(), times.end());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        priority_queue<int , vector<int> , greater<int>> st;
        int chair = 0;

        for (auto itr : times) {
            int arival = itr[0];
            int departure = itr[1];

            while (!pq.empty() && arival > pq.top()[0]) {
                st.push(pq.top()[1]);
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