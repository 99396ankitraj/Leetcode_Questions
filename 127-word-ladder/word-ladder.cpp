class Solution {
public:
    int ladderLength(string &b, string e, vector<string>& w) {
        int n = w.size();
        int m = w[0].length();
        int ind = -1, ind2 = -1;

        // Create a map to store word indices
        map<string, int> mp;
        for (int i = 0; i < n; i++) {
            mp[w[i]] = i;
        }

        // Check if the end word is not in the map
        if (mp.find(e) == mp.end()) return 0;

        // If the begin word is not in the map, add it and set flag
        bool flag = false;
        if (mp.find(b) == mp.end()) {
            mp[b] = n;
            flag = true;
        }

        // Create adjacency list for BFS
        vector<vector<int>> adj(flag ? n + 1 : n);  // Account for potential added start word

        // Build the adjacency list by checking each word's one-letter transformations
        for (auto top_ele = mp.begin(); top_ele != mp.end(); ++top_ele) {
            string str1 = top_ele->first;
            int num1 = top_ele->second;

            for (auto itr = next(top_ele); itr != mp.end(); ++itr) {
                string str2 = itr->first;
                int num2 = itr->second;

                int count = 0;
                for (int i = 0; i < m; i++) {
                    if (str1[i] != str2[i]) count++;
                    if (count > 1) break;  // No need to continue if more than 1 character differs
                }

                if (count == 1) {
                    adj[num1].push_back(num2);
                    adj[num2].push_back(num1);
                }
            }
        }

        // Start BFS from the beginning word
        int startIdx = flag ? n : mp[b];
        int endIdx = mp[e];

        queue<int> q;
        vector<int> dist(flag ? n + 1 : n, INT_MAX);

        q.push(startIdx);
        dist[startIdx] = 0;

        while (!q.empty()) {
            int top = q.front();
            q.pop();

            for (int neighbor : adj[top]) {
                if (dist[top] + 1 < dist[neighbor]) {
                    dist[neighbor] = dist[top] + 1;
                    q.push(neighbor);
                }
            }
        }

        // Return the distance to the end word or 0 if not reachable
        return dist[endIdx] == INT_MAX ? 0 : dist[endIdx] + 1; // +1 for including the end word
    }
};
