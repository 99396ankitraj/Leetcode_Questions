class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long n = nums.size() , ans = 0 , sum = 0;
        unordered_set<int> st;
        int i = 0 , j = 0;
        while(j < n){
            if(st.find(nums[j]) != st.end()){
               while(nums[i] != nums[j]){
                    sum -= nums[i];
                    st.erase(nums[i++]);
               }
                sum -= nums[i];
                st.erase(nums[i++]);
            }
            st.insert(nums[j]);
            if((j - i + 1) == k){
                sum += nums[j];
                ans = max(ans , sum);
                st.erase(nums[i]);
                sum -= nums[i++];

            }else{
                sum += nums[j];
            }
            j++;
        }
        return ans ;
    }
};