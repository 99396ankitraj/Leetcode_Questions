class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size() , Xor = 0;
        int maxi = pow(2 , maximumBit) - 1;

        for(int i = 0 ; i < n ; i++){
            Xor ^= nums[i];
            nums[i] = Xor;
        }

        vector<int>ans;
        n--;

        while(n >= 0){
            ans.push_back(maxi - nums[n]);
            n--;
        }

        cout<<maxi;
        return ans;
    }
};