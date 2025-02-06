class Solution {
public:
    void generateSubsequences(
        int ind, vector<int>& nums,
        unordered_map<int, vector<pair<int, int>>>& productMap) {
        if (ind == nums.size())
            return;

        for (int ind = 0; ind < nums.size(); ind++) {
            for (int i = ind + 1; i < nums.size(); ++i) {
                int product = nums[ind] * nums[i];
                productMap[product].push_back({nums[ind], nums[i]});
            }
        }
    }

    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, vector<pair<int, int>>> productMap;
        generateSubsequences(0, nums, productMap);

        int result = 0;

        for (const auto& [product, pairs] : productMap) {
            if (pairs.size() > 1) {
                int count = pairs.size();
                result += (count * (count - 1)) * 4;
            }
        }
        return result;
    }
};
