class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size() , i = 0 , j = 1;
        if(k == 1 ) return nums;
        vector<int> ans(n - k + 1 , -1);
        while(j < n){
            if(nums[j-1] < nums[j] && nums[j-1]+1 == nums[j]){
               if((j - i + 1) == k){
                  ans[j-k +1] = nums[j];
                  i++;
               }
            }else i = j;
            
              j++; 
        }
      return ans;
    }
};