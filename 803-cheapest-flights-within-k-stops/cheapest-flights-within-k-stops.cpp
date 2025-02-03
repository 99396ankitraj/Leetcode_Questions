class Solution {
public:
    typedef pair<int,pair<int,int>> p;

    int findCheapestPrice(int n, vector<vector<int>>& flight, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (int i = 0; i < flight.size(); i++) {
            adj[flight[i][0]].push_back({flight[i][1], flight[i][2]});
        }

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        queue<p> pq;
        pq.push({0, {src, 0}});

        while (!pq.empty()) {
            auto top = pq.front();
            pq.pop();

            int cost = top.first;
            int city = top.second.first;
            int stops = top.second.second;

            if (stops > k) continue;

            for (auto& it : adj[city]) {
                int nextCity = it.first;
                int nextCost = it.second;

                if (cost + nextCost < dist[nextCity][stops + 1]) {
                    dist[nextCity][stops + 1] = cost + nextCost;
                    pq.push({cost + nextCost, {nextCity, stops + 1}});
                }
            }
        }

        int minCost = INT_MAX;
        for (int i = 0; i <= k + 1; ++i) {
            minCost = min(minCost, dist[dst][i]);
        }

        return minCost == INT_MAX ? -1 : minCost;
    }
};
