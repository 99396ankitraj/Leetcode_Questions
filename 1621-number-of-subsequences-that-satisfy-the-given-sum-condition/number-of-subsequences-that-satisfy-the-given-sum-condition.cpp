class Solution {
public:
    int mod = pow(10 , 9)+7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0 , j = n-1;
        sort(nums.begin(),nums.end());
        
        vector<int> power(n , 1);
        for(int k = 1 ; k < n ; k++){
            power[k] = (power[k - 1] * 2) % mod;
        }
        int ans = 0;

        while(i <= j){
            if(nums[i]+nums[j] <= target){
                ans = (ans + power[j - i]) % mod;
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }
};