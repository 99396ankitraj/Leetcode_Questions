class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;

        if(nums[0] <= nums[(low+high)/2] && nums[(low+high)/2] <= nums[high]) return nums[0];
        while(low < high){
            int mid = (low+high)/2;
            if(nums[0] <= nums[mid]){
                low = mid+1;
            }else{
                high = mid;
            }
        }
       return  nums[low]; 
    }
};