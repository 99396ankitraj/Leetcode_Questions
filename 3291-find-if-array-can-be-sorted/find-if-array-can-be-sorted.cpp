class Solution {
public:
    bool canSortArray(vector<int>& nums) {
         int n =  nums.size() , i = 1;
         if(n <= 1) return true;
         while(i < n){
            int j = i;
            while(j > 0 && nums[j-1] > nums[j]){
                if(__builtin_popcount(nums[j-1]) != __builtin_popcount(nums[j])) return false;
                 swap(nums[j-1] , nums[j]);
                 j--;
            }
            i++;
         }
      return true;
    }
};