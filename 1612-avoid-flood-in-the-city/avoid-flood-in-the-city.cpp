class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int, int> lakeMap; // Stores the last day a lake was full
        set<int> dryDays; // Stores the indices of dry days
        vector<int> result(n, -1); // Initialize result with -1

        for (int i = 0; i < n; ++i) {
            if (rains[i] == 0) {
                dryDays.insert(i); // Store the dry day index
            } else {
                int lake = rains[i];
                if (lakeMap.count(lake)) {
                    auto it = dryDays.upper_bound(lakeMap[lake]); // Find the first dry day after the last rainy day for the same lake
                    if (it == dryDays.end()) {
                        return {}; // No valid dry day to prevent flood
                    }
                    result[*it] = lake; // Dry the lake on the found dry day
                    dryDays.erase(it); // Remove the used dry day
                }
                lakeMap[lake] = i; // Update the last day the lake was full
            }
        }

        // Fill remaining dry days with any number, e.g., 1 (or any other appropriate number)
        for (int day : dryDays) {
            result[day] = 1;
        }

        return result;
    }
};
