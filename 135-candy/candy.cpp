class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 1) return 1;

        int totalCandies = 1; // First child gets 1 candy
        int up = 0, down = 0, peak = 0;

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                // Increasing slope
                up++;
                peak = up;
                down = 0; // Reset down slope
                totalCandies += up + 1;
            } else if (ratings[i] < ratings[i - 1]) {
                // Decreasing slope
                down++;
                up = 0; // Reset up slope
                totalCandies += down;
                if (down > peak) {
                    totalCandies++;
                }
            } else {
                // Flat slope
                up = down = peak = 0;
                totalCandies += 1;
            }
        }

        return totalCandies;
    }
};