class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int i = 0, j = plants.size()-1, ans = 0;
        int tankA = capacityA, tankB = capacityB;

        while (i <= j) {
            if (i == j) {
                if (tankA >= plants[i] || tankB >= plants[i]) {
                    return ans; // A single person can water the last plant
                } else {
                    return ans + 1; // Either person needs one more refill to water the last plant
                }
            }

            if (tankA >= plants[i]) {
                tankA -= plants[i];
            } else {
                tankA = capacityA - plants[i];
                ans += 1;
            }

            if (tankB >= plants[j]) {
                tankB -= plants[j];
            } else {
                tankB = capacityB - plants[j];
                ans += 1;
            }
            i++;
            j--;
        }
        return ans;
    }
};
