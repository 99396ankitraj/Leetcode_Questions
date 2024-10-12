class Solution {
public:
    int minGroups(vector<vector<int>>& times) { 
        ios_base::sync_with_stdio(false); 
        cout.tie(nullptr);
        cin.tie(nullptr);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int station = 0;

        sort(times.begin(), times.end());

        for (const auto& itr : times) {
            int arrival = itr[0];
            int departure = itr[1];

            if (!pq.empty() && arrival > pq.top().first) {
                pq.push({departure, pq.top().second});
                pq.pop();
            } else {
                pq.push({departure, station++});
            }
        }
        return station;
    }
};

