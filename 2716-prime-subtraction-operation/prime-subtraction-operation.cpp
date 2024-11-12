
class Solution {
public:
    void seive(vector<bool>& isPrime) {
        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i * i <= 1000; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= 1000; j += i) {
                    isPrime[j] = false; // Corrected from isPrime[i] to isPrime[j]
                }
            }
        }
    }

    bool primeSubOperation(vector<int>& nums) {
        vector<bool> isPrime(1001, true);
        int n = nums.size();

        seive(isPrime);

        if (n <= 1) return true;

        for (int i = n - 1; i >= 1; i--) {
            if (nums[i] > nums[i - 1]) continue;
            else {
                bool found = false;
                for (int p = 2; p < nums[i - 1]; p++) {
                    if (isPrime[p] && nums[i - 1] - p < nums[i]) {
                        nums[i - 1] -= p;
                        found = true;
                        break;
                    }
                }
                if (!found || nums[i - 1] >= nums[i]) return false;
            }
        }
        return true;
    }
};
