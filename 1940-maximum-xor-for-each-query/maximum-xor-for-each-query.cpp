class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int mb) {
        
        int n = nums.size();
        int k = (1<<mb)-1;
        int xor_sum = accumulate(nums.begin(), nums.end(), 0,bit_xor<int>());
        vector<int> ans;

        for(int i = n-1; i>= 0; i--)
        {
            ans.push_back(xor_sum^k);
            xor_sum^=nums[i];
        }

        return ans;
    }
};
